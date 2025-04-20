# Object-Based C Coding Style

## 개요

C 언어에서 **모듈성**, **캡슐화**, **추상화**, **방어적 프로그래밍** 원칙을 따르는 코딩 스타일입니다. 객체 지향의 일부 개념을 모방하여 유지보수성과 안정성을 높입니다.

## 핵심 원칙 및 스타일 요약

*   **모듈성 (Modularity)**
    *   `.h` (인터페이스)와 `.c` (구현) 분리.
    *   헤더 가드 (`#ifndef`/`#define`/`#endif`) 사용.
    *   C++ 호환성 (`extern "C"`) 처리.
    *   **스타일:** 모든 공개 심볼에 **모듈 접두사** (`example_`, `EXAMPLE_`) 사용.

*   **캡슐화 (Encapsulation)**
    *   내부 상태와 헬퍼 함수는 `.c` 파일에 `static`으로 선언하여 숨김.
    *   **스타일:** 비공개 전역 변수는 `static g_` 접두사 사용 (`static g_example_contexts`).
    *   외부 접근은 공개 함수 API를 통해서만 허용.

*   **추상화 (Abstraction)**
    *   명확한 인터페이스 제공, 복잡한 내부 구현 은닉.
    *   **스타일:** `typedef`로 추상 타입 정의 (`_t` 접미사, 예: `example_id_t`). 구조체는 `struct` 키워드로 직접 사용. **일관된 명명 규칙** 적용.

*   **방어적 프로그래밍 (Defensive Programming)**
    *   컴파일 타임 (`sizeof` 검사, `const`), 디버그 타임 (`assert`), 런타임 (입력 검증) 검사 활용.
    *   **스타일:** 명시적 결과 코드 (`_result_t` 타입, `#define` 상수) 사용.

## 스타일 규칙 상세

### 명명 규칙 (Naming Conventions)

*   **모듈 접두사 (Module Prefix)**: 모든 공개 심볼(함수, 타입, 상수)은 `모듈명_` 또는 `모듈명_` (상수)로 시작.
    ```c
    void example_init(example_id_t id);
    typedef uint8_t example_id_t;
    #define EXAMPLE_DATA_COUNT_MAX (20)
    ```
*   **타입 정의 (`typedef`)**: `snake_case_t` 접미사 사용.
    ```c
    typedef uint8_t example_id_t;
    typedef int8_t example_set_data_result_t;
    ```
*   **구조체 (Structs)**: `struct` 키워드로 직접 정의 및 사용 (typedef로 가리지 않음).
    ```c
    struct example_data { /* ... */ };
    void process_data(struct example_data* data);
    ```
*   **상수/결과 코드 (`#define`)**: `ALL_CAPS_SNAKE_CASE` 사용. 결과 코드는 `<모듈>_<동사>_<명사>_RESULT_<상태>` 패턴 권장.
    ```c
    #define EXAMPLE_ID_MAX (2)
    #define EXAMPLE_SET_DATA_RESULT_SUCCESS (0)
    #define EXAMPLE_SET_DATA_RESULT_ERROR_INVALID_ID (-3)
    ```
*   **함수 / 변수 / 구조체 멤버**: `snake_case` 사용.
    ```c
    void example_get_data_count(void);
    uint32_t current_data_count;
    struct example_data { uint8_t data1[4]; };
    ```
*   **출력 파라미터**: `_out` 접미사 사용.
    ```c
    bool example_get_data(example_id_t id, struct example_data data_out[]);
    ```
*   **비공개 전역 변수**: `static g_` 접두사 사용.
    ```c
    // example.c
    static struct example_context g_example_contexts[EXAMPLE_ID_MAX];
    ```

### 파일 구조 및 기본 설정

*   `.h` 파일: 공개 인터페이스 선언. 최소한의 `#include`.
*   `.c` 파일: 구현 정의. 자신의 헤더 파일 우선 `#include`.
*   헤더 가드 및 C++ 호환성 처리 적용.

### 캡슐화 (`static`)

*   `.c` 파일 내 비공개 전역 변수/함수는 `static` 선언.

### 데이터 타입 및 구조체

*   `<stdint.h>`, `<stdbool.h>` 표준 타입 사용.
*   구조체는 `struct` 키워드로 정의.

### 결과 코드 처리

*   결과 타입은 `typedef <type> <module>_result_t;` 형식으로 정의.
*   결과 값은 `#define` 상수로 정의.
    ```c
    // example.h
    typedef int8_t example_set_data_result_t;
    #define EXAMPLE_SET_DATA_RESULT_SUCCESS (0)
    // ... other codes
    ```
*   함수는 정의된 `_result_t` 타입 반환.

### 방어적 프로그래밍 기법

*   **`const` 정확성**: 변경되지 않는 포인터 파라미터에 `const` 사용.
    ```c
    void process_data(const struct example_data* data);
    ```
*   **`assert` 사용**: 개발 중 `.c` 파일 내에서 사전/사후 조건 검증 (`#include <assert.h>`).
    ```c
    assert(ptr != NULL);
    ```
*   **`sizeof` 검사기**: 디버그 빌드 시 `#ifndef NDEBUG` 내에서 구조체 크기 등 컴파일 타임 검증.
    ```c
    #ifndef NDEBUG
      int checker[sizeof(struct example_data) == 8 ? 1 : -1];
    #endif
    ```
*   **런타임 검사**: 공개 함수 시작 시 입력 값 검증 후 정의된 결과 코드 반환.
    ```c
    if (id >= EXAMPLE_ID_MAX) return EXAMPLE_RESULT_ERROR_INVALID_ID;
    ```

### 기타

*   **매크로 위치**: 파일 상단 또는 사용 직전에 정의.
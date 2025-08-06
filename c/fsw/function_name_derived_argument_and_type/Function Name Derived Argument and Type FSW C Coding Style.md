# 함수명 기반 타입 유도 코딩 스타일
## Function Name Derived Argument and Type Coding Style

## 개요
함수 이름으로부터 반환 타입, 인자 타입, 관련 상수가 자동으로 결정되는 C 코딩 규약입니다.

## 핵심 규칙

### 1. 반환 타입
함수는 세 가지 반환 타입 패턴 중 하나를 사용:
- `void` - 반환값 없음
- `bool` - 단순 성공/실패
- `<함수명>_result_t` - 상세 결과 코드

### 2. 반환 타입 정의
상세 결과를 반환하는 함수:
```c
typedef int8_t <함수명>_result_t;
```

### 3. 결과 상수
결과 코드를 매크로로 정의:
```c
#define <함수명_대문자>_RESULT_SUCCESS (1)
#define <함수명_대문자>_RESULT_FAIL_<이유> (음수값)
```

### 4. 함수 인자
인자는 다음 순서를 따름:
1. 인스턴스/디스크립터 (필요시)
2. 함수별 파라미터 (함수명에서 유도)
3. 옵션 구조체 (필요시): `struct <함수명>_options`

### 5. 옵션 구조체
선택적 파라미터용:
```c
struct <함수명>_options {
    // 선택적 파라미터들
};
```

## 예제

```c
// 함수: xx_write_data

// 반환 타입 정의
typedef int8_t xx_write_data_result_t;

// 결과 상수
#define XX_WRITE_DATA_RESULT_SUCCESS (1)
#define XX_WRITE_DATA_RESULT_FAIL_UNDEFINED (-1)
#define XX_WRITE_DATA_RESULT_WRONG_DATASIZE (-2)

// 옵션 구조체
struct xx_write_data_options {
    uint32_t timeout_ms;
    bool verify_after_write;
};

// 함수 선언
xx_write_data_result_t xx_write_data(
    xx_id_t id,           // 인스턴스 식별자
    uint8_t *data,        // 함수명에서 유도
    uint32_t data_size,   // 함수명에서 유도
    struct xx_write_data_options options  // 선택적 파라미터
);
```

## 장점
- **예측 가능**: 함수명으로 타입 추론 가능
- **일관성**: 전체 코드베이스에 균일한 패턴
- **자체 문서화**: 함수명이 인터페이스를 설명
- **유지보수성**: 함수명별로 관련 타입 그룹화

## 빠른 참조
| 함수명           | 반환 타입                  | 옵션 구조체                       | 상수                     |
| ------------- | ---------------------- | ---------------------------- | ---------------------- |
| `foo_bar`     | `foo_bar_result_t`     | `struct foo_bar_options`     | `FOO_BAR_RESULT_*`     |
| `init_device` | `init_device_result_t` | `struct init_device_options` | `INIT_DEVICE_RESULT_*` |
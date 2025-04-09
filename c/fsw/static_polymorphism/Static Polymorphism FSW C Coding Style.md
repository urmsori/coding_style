# C 코딩 스타일: 정적 다형성 구현 (개조식)

## 목적

*   빌드 시 Configuration(구성) 선택을 통해, 동일 인터페이스를 갖는 컴포넌트의 구현을 다르게 결정 (정적 다형성).
*   런타임 오버헤드 없이 Configuration 최적화 코드 생성.

## 핵심 원리

*   동일 인터페이스 (`component.h`)에 대해, 빌드 시 선택된 Configuration(`a`, `b` 등)의 특화 구현 (`specific/..._specific_{config}.c`)을 링크하여 동작 변경.

## 디렉토리 및 파일 역할

*   `component/`: 공통 요소 디렉토리.
    *   `component.h`: 공통 인터페이스 선언.
    *   `component.c`: (선택 사항) 모든 Configuration 공통 로직 구현.
*   `define/`: Configuration별 정의 루트 디렉토리.
    *   `define/{config}/`: 특정 Configuration(`a`, `b` 등) 하위 디렉토리.
    *   `component_define.h`: 해당 Configuration의 매크로, 타입 등 정의. `component.h`가 포함.
*   `specific/`: Configuration별 특화 구현 루트 디렉토리.
    *   `specific/{config}/`: 특정 Configuration(`a`, `b` 등) 하위 디렉토리.
    *   `component_specific_{config}.c`: `component.h` 함수의 해당 Configuration 특화 구현. 핵심 구현부.
    *   component_specific_{config}.h: (선택 사항) 해당 Configuration 전용 추가 인터페이스 선언.


## 핵심 의존성 규칙 (#include)
*   component.h:
    *   `component_define.h` 포함 필수 (`#include "component_define.h"`). 빌드 시스템이 경로 제공.
    *   `specific` 디렉토리의 헤더 포함 금지.
*   `define/.../component_define.h`:
    *   다른 프로젝트 헤더 포함 금지 (표준 라이브러리 최소 허용).
*   `specific/.../component_specific_{config}.c`:
    *   `component.h` (또는 `..._specific_{config}.h` 존재 시 해당 파일) 포함 필수.
*   `specific/.../component_specific_{config}.h`:
    *   `component.h` 포함 필수.
*   `component.c`:
    *   `component.h` 포함 필수.
    *   `define` 또는 `specific` 디렉토리 파일 직접 포함 금지. `#ifdef` 사용은 제한적 허용 (빌드 시스템 매크로 정의 시).

## 빌드 시스템 필수 요구사항

*   Configuration 식별 기능 제공.
*   선택된 Configuration의 `define/{config}` 경로를 include path 최우선 지정.
*   `component.c`(존재 시) 및 활성 Configuration의 `specific/.../component_specific_{config}.c`만 컴파일/링크 대상 포함.

## 네이밍 규칙

*   파일/함수: `snake_case`.
*   `define`/`specific` 파일명: 제시된 패턴(`component_define.h`, `component_specific_{config}.c` 등) 준수.
*   매크로/타입: 컴포넌트/Configuration 접두사 사용 권장 (예: `COMPONENT_A_`).
# FSW C Naming Definition
## 동사
### get/set/read/write/send/receive/load/save
* get/set
 * 내부 변수
* read/write
 * 외부인데, 즉시 반영
* send/receive
 * 외부이고, 즉시가 아닐 수 있음
 * blocking/non-blocking/sync/async를 붙여야한다
* load/save
 * TBD

### on/off, enable/disable
함수를 각각 만드는게 좋다
합치고 싶다면 get/set, read/write로 대체할수있다

## 명사
### index/number
index는 무조건 0부터 시작한다.
0이 아닌 1부터 시작해야하는 경우 number를 붙인다.

### size/count
기본적으로 size를 사용하면 된다. size는 byte_size가 기본이고, bit_size인 경우 명시한다.
count는 묶음을 하나로 하고싶을때 count를 사용한다.
struct array의 size는 byte 크기
struct array의 count는 element의 개수

## 접미어
### blocking/non-blocking/sync/async
|       | Blocking                                  | Non-Blocking |
| ----- | ------------------------------------------ | ------------ |
| Sync  | 작업 완료까지 대기, 다른 작업 불가           | 작업 상태 주기적 확인, 다른 작업 가능 |
| Async | 별도 스레드에서 작업, 메인 스레드는 계속 실행 | 이벤트 기반, 콜백으로 결과 처리, 즉시 제어 반환 |

### MAX
어떤것의 최대값을 나타낼때는 무조건 MAX를 사용한다.
다른 경우가 필요하다면 이 문서 업데이트 해야함.

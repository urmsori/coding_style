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
TBD

## 접미어
### blocking/non-blocking/sync/async
|       | Blocking                                  | Non-Blocking |
| ----- | ------------------------------------------ | ------------ |
| Sync  | 작업 완료까지 대기, 다른 작업 불가           | 작업 상태 주기적 확인, 다른 작업 가능 |
| Async | 별도 스레드에서 작업, 메인 스레드는 계속 실행 | 이벤트 기반, 콜백으로 결과 처리, 즉시 제어 반환 |
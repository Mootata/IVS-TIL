# CAN Arbitration

# CSMA

Msg ID가 낮을수록 순위가 높은 것

## CSMA/NBA

1. Tx = d(0), Rx = d(0)
   - 중재중 전송
2. Tx = r(1), Rx = r(1)
   - 중재중 전송
3. Tx = r(1), Rx = d(0)
   - 중재 상실
4. Tx = d(0), Rx = r(1)
   - 중재 에러

##

시작은 0  
ID를 포함한 우선순위를 나타내는 11비트  
standby = 출력전압 1, 다른 node의 전압에 따라 0, 1이 결정될 수 있기 떄문  
하드웨어적인 보안 이슈 존재, DOS(0만 보내는 node를 만드는 경우)

## Ethernet vs CAN

### Ethernet

- 전송속도: 10Mbps ~ 1Gbps
- 송신단위: Frame [64 ~ 1500 byte]
- 페이로드가 길어서 다량의 데이터 전송에 적합하지만, 실시간성이 나쁨
- 누구에게 보내는지

### CAN

- 전송속도: 1Mbps
- 송신단위: Data Frame [=Message] [0 ~ 64 byte]
- 페이로드가 짧아서 실시간성이 좋지만, 다량의 데이터 전송에 부적합
- 어떤 메시지를 보내는지
- 일정 간격으로 요청된 데이터를 보낼뿐, 누가 받을지는 상관없음

## Frame Type

### Data Frame

Data를 송신하기 위한 Frame, RTR = 0  
Data Frame에 IDE, r0같은 안쓰는 비트가 있는 이유는 나중에 확장을 위함, 이 두값을 0, 1로 표현함으로써 4개의 버전을 더 만들 수 있음.  
없을 때는 무조건 비트를 추가하고, 더이상 호환되지 않는 이전에 사용하던 버전을 밀어버려야 함.

DLC = Data Field의 길이를 byte로 나타낸 값

Data Frame 버전간의 우선순위: 2.0A Data Frame - 2.0A Remote Frame - 2.0B Data Frame - 2.0B Remote Frame  
message table을 만들 때, 같은 break 값이라고 해도 node ID를 다르게 줘야함

### Remote Frame

Data Frame을 요구하기 위한 Frmae, RTR = 1, Data Field 없음 (Lin등을 활요하여 알아서 주기적으로 체크하기 때문에, 잘 사용하지 않는 추세)

ID를 체크할 때 RTR값 까지 함께 비교함, Bus에 데이터 요청과 송신이 동시에 존재할 수 있기 때문에 어차피 데이터가 이미 전송될 예정이기 때문에 수신 요청을 버림.

### Error Frame

Error를 통지하는 Frame (에러를 알리기 위해 일부러 Bit Stuffing을 파괴)

0을 6개 보냄, 기존에는 연속으로 같은 값이 5개 이상 들어가면, 다른 값 1개를 넣어서 구분했기 때문에, 이를 통해서 에러라는 것을 알 수 있음

### Overload Frame

HW 성능상 당장 수신할 수 없음을 통지하는 Frame, HW의 발달로 요즘은 사용하지 않음

## CAN Protocol

### ACK

ACK 값이 하나라도 0이 된다면, 모두 0이 된다.

## Can Frame 예제(2)

노드 C Remote(0x121)은 이미 노드 A에서 송신하므로 필요없음.

## Can Frame 예제(9)

Bit Stuffing은 CRC까지만 적용. (EOF는 1이 7개라서)

## Can Frame 예제(10)

0 [001 0010 00010 0 0 0001 0001 1011] 100001011010001 101 1111111 111
0 [001 0010 00010 0 0 00(1)01 0001 1011] 100001011010001 101 1111111 111

## CAN 파형 예제(1)

CAN_H 파형

1. 2.0A / 2.0B = 2.0A (SOF부터 13~15번째 비트가 000이므로 2.0A)
2. Frame Type = DataFrame (SOF부터 13번째 비트인 RTR이 0이므로 DataFrame)
3. Message ID = 01000001000001 (Bit Stuffing 적용)
4. Payload Data =
5. CRC Data = 10111101111101011

# Controller

송수신 완료시에 CPU에게 알리기 위해 Interrupt 발생

## Mask 지정

mask Register = 체크해야하는 범위  
filter Register = 실제로 원하는 값

0x120 = 001 0010 0000  
0x13F = 001 0011 1111  
Mask Register = 111 1110 0000 (내가 보고싶은 범위만 0으로 채우고, 나머지 1)  
Filter Register = 001 0010 0000 (내가 확인해야하는 범위 동일하게, 나머지 0)

## Mask 지정 예제 (4)

Receivdes Message ID 0x120, 0x122, 0x124, 0x126  
001 0010 0000
001 0010 0010
001 0010 0100
001 0010 0110

Mask Register = 111 1111 1(00)1
Filter Register = 001 0010 0(00)0

## Mask 지정 예제 (5)

Receivdes Message ID 0x109, 0x10B, 0x10D, 0x10F, 0x129, 0x12B, 0x12D, 0x12F

001 0000 1001  
001 0000 1011  
001 0000 1101  
001 0000 1111  
001 0010 1001  
001 0010 1011  
001 0010 1101  
001 0010 1111

Mask Register = 111 11(0)1 1(00)1  
Filter Register = 001 00(0)0 1(00)1

## CAN Error Handling

### Ack Error

### Bit Error

내가 보낸 값과 bus 전압이 다른경우, (송신단이 발견)  
이것이 가능한 경우는 ACK (1을 보냈을 때, 0이 오는 것, BUS의 ACK자리에 0이 오는 것)

### Form Error

고정 Format위반 검출 (항상 1로 고정된 값이 0이 되었다던지)

### Stuff Error

Bit Stuffing이 제대로 적용되지 않은 경우 (111111, 000000)  
수신단은 원래 ACK 이외에는 응답하면 안되지만, 에러를 검출한 경우 응답

### CRC Error

전송된 CRC와 계산한 CRC의 불일치

### Error 검출 범위

1. ACK ERROR: 수신을 잘 했는지, ACK 값이 1인지
2. Bit Error: 내가 송신한대로 Bus에 잘 올라 갔는지
3. Form Error: CRC Del, ACK Del, EOF 값이 모두 1인지
4. Stuff Error: Bit Stuffing이 제대로 적용되었는지
5. CRC Error: CRC 값의 계산에 오류가 없는지

### CRC (Cyclic Redundancy Check)

오류 복구도 가능하지만, 재전송만 함  
CRC로 처리할 정보 비트열은 최대 83비트 (SOF 1 + Arbitration Field 12 + Control Field 6 + Data Field 0 ~ 64 = 83)

### Error Counter

잦은 에러를 발생시키는 노드에 count를 통해 패널티를 부여하는 것 (송신 에러)

1. Error Active

   - Error Flag를 송출 (0 6개)

2. Error Passive

   - Suspend Transmission = 8bit (기다리는 동안 다른 노드들이 송신을 마치기 떄문에, 비어있는 동안 송신 시도)
   - Error Flag를 송출 (1 6개)

3. Bus Off

### Receive Error Counter (REC)

해당 노드가 먼저 0 6개를 보냈는데, 이후에 0이 더 나오면 count를 8 증가 시키고, 다른 노드가 발생시킨 Error에 반응해서 0을 보내면 count +1

### Error Frame

1001 000111  
Tx 100(0 error) (000000 error flag)  
Rx 1(000000 error라고 판단하고 뒤로 06개 보냄) (000000 Error flag)

따라서 송신단에서는 100 (0 000000000) 9bit라고 판단

Secondary Error Flag

### Error Frame 예제(1)

해당 노드가 송신한 Error flag 뒤로 0이 더 있으면 Error count +8 아니면 +1

### Error Frame 예제(6)

1. sender는 ACK필드 이후 에러를 발견해서 Error Flag 전송 (+8)
2. 1번 receiver는 sender가 보낸 데이터의 CRC계산에서 에러를 발견하여 더 빠르게 error flag 전송 (+8)
3. 2번 receiver는 1번 receiver가 ACK를 1로 설정했으므로, Form error 발견으로 인한 error flag 전송 (+1)

Receiver 입장에서 error를 발견하고 flag를 송신하려고 했는데, 마침 ACK 송신을 해야하는 자리여서 Error flag인지 ACK 0인지 판단할 수 없으므로, 일단 ACK 1을 보내고, 그 뒤에 0 6개를 보냄

# CAN-FD (CAN Flexible Data Rate)

## CAN-FD Frame

BRS(Bit Rate Switch)를 기준으로 전송 속도가 빨라짐.  
CRC = 27b (17 + 10) or 32b(21 + 16)  
FSB = 바로 앞비트와 상반되는 비트  
(Even)Parity = 짝수개인지 체크하는 비트

## CAN-FD의 대역폭

앞뒤에 존재하는 Arbitration Phase와 ACK Phase의 속도는 그대로기 떄문에 속도가 5배 증가하는 것은 아니고, 중간에 있는 Payload, Data length가 길수록 속도가 빨라진다.

p203~205 HW내용이므로 넘어감

## CAN-Classic과 CAN-FD의 혼용

CAN-FD를 사용할 때는 CAN-Classic을 sleep 상태로 전환하여 에러가 발생하지 않도록 함.

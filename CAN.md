# CAN (Controller Area Network)

표준, 법률로 인한 전자장치 탑재, SUMS  
Body: 편의, 안전, 인테리어, 보안  
chassy: 파워트레인, 제동 조향  
SCC ?  
Ring: Most  
Bus: CAN, LIN, FlexRay  
Arbitrary network structure: Ethernet  
Star: FlexRay

L1: Transceiver 정의  
L2: Controller (frame 씌워줌)

ISO 11898

- -1: CAN Protocoal (CAN and CAN FD)
- -2: High Speed Physical  
  CAN 최대 속도는 500mb가 아닌 1000

## Physical Layer

### Classification of bus systems

Class A: LIN 20kBit/s  
Class B: CAN(LOW SPEED) 125kBit/s  
ClassC CAN(High Speed) 1Mbit/s  
Not defined: CAN FD(High Speed), Not defined  
Infotainment: MOST, 150MBit/s

**Automotive Ethernet (IEEE 100Base - T1, 1000Base - T1(= Twisted 1Pair 선 한쌍))**

CAN_H, CAN_L 전압 차이에 따른 값  
같으면 1 다르면 0, 0 = dominant, 1 = recessive

## Addressing

1. Node Adrredssing
   - Peer to Peer (1:1)
   - Use in Ethernet
2. Broadcast Addressing
   - Broadcast (1:N)
   - Used in CAN

어떤 내용을 보낼건지 Tx, 어떤 내용을 받을건지 Rx  
Communication Matrix

## Bus Access

Multiple Master Structure, CSMA / CR  
Arbitration Bit by Bit  
여러 Node가 동시에 값을 Bus에 올리고, 이를 반영한다. 이때, 값이 Dominant 된다면, 자신보다 우선순위가 높은 노드가 존재한다는 의미이므로 전송을 멈춘다.

ID가 낮을수록 우선순위가 높다.  
CAN은 Bus Node에 민감하다는 단점

## CAN Framing
CAN Data Frame Standard Format -> CAN Data Frame Extended Format (identifier 11 Bit - > 29 Bit)

### Structure of CAN Data Frame in Standard Format

- Start Of Frame (SOF): NRZ
- Identifier: 우선순위 (0에 가까울 수록 우선순위가 높음)
  - msb: 최상위 비트 (먼저 읽는 비트)
  - lsb: 최하위 비트
  - little endian 낮은 비트 = msb = intell
  - big endian 높은 비트 = msb = motorola
- Data Field: 8 Byte (너무 작아서 이를 해결하기 위해 CAN FD 나옴)

### Remote Transmission Request (RTR)

### Identifier Extension

Standard, Extended format은 같은 버스에서 사용할 수 있음. (arbitration에는 차이가 없기 때문)  
둘의 우선순위가 동일한 경우 RTR 활용 (Identifier에 RTR까지 포함되는 이유)

Extended 같은 경우 끝에 꼭 x을 붙여줘야 함. (0x0 같은 값의 format의 구별을 위해서)

exercise2
00100100011 뒤쪽부터 채우고 범위를 벗어나는 최상위 비트는 버린다.  
extended 중간에 SRR IDE는 무시하고 작성하면 됨. 모자른 부분은 0으로 채운다.

### Data Length Code and Data Field

0-8: Number of bytes in Data Field  
9-15: Eight bytes in Data Field

### Cyclic Redundancy Check (CRC)

sender가 만든 코드로 receiver가 데이터의 유효성 체크

### Acknowledgement

receiver가 보내는 CRC에 대한 결과값  
dominant = 잘 받지 못함  
recessive = 잘 받음

### End of Frame and Intermission

DEL(1Bit), EOF(7Bit), ITM(3Bit) => 11 x 1 means bus idle  
1비트는 2us(마이크로세크), 1frame(108Bit) = 250us

### Bit Stupping

0xFFFF = 1111 1111 1111 1111 => 11비트 이상이 1이므로 bus idle 상태로 진입함.  
따라서 이를 방지하기 위해서 0이든 1이든 연속된 같은 값 5개마다 상반된 비트를 삽입  
EX) 111 1(0)111 11(0)11 111(0)1 (19Bits), Stupping Bit마저도 연속되는 경우 동일하게 상반된 비트를 넣어야 함. 1111 1(0)000 0(1)11

### Signals

1. symbolic names
2. units assignment
3. Conversion formula : hex Raw value를 Decimal 값으로 변환해주는 기능
4. symbolic values

Bit rate 초당 보낼 수 있는 bit의 수  
Baud rate 초당 보낼 수 있는 심볼의 개수

### Example Data Exchange

## Data Protection

## Synchronization

## CAN with Flexible Datarate

## 알아둬야할 것

1. OSI 레퍼런스 모델
2. implementation (컨트롤러와 트렌시버)
3. CAN_H, CAN_L의 전압차이로 신호 처리 (전압차이가 업으면 dominant, 있으면 recessive)  
4. CAN은 Data 필드가 8바이트, 총 5개의 필드가 있음
5. Bit Stupping 
6. 
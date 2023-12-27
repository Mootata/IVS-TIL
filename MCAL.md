최윤순 010 2521 2450
yunsunchoi@hlcompany.com

# 1일차

## 차량용 SW 특징

1. 높은 진입장벽
2. 높은 안전 등급 요구: ASIL
3. 비교적 낮은 하드웨어 성능
4. 실시간 요구

## MCU Information

여러개로 나눠진 폰노이만 구조를 한데 모아둔 것이 MCU

## 개발 환경

### 기자재

1. Wire harness: 전선 꾸러미
2. ECU(SCU Gen6): Dap Connector (커넥터, 통신 = Jtag)
3. Can Case: CAN통신 장비 (Vector VN1610)

### File Format

elf: 심볼까지 들어있어 크기가 크지만, 디버깅 가능  
hex: 바이너리마 들어있어 크기가 작음

### MCU

MCU의 메모리 주소는 80000000부터 시작, 이로부터 2MB  
hex파일의 끝에 S7은 시작주소를 의미

### FPU

실수 계산은 느려서, 이를 위한 전용 HW

# DIO (Digital Input Output)

### INHIBIT

IGN이 REGULATOR MODULE을 켜면, RM이 MCU를 통해 INHIBIT을 1로 만든다.  
그럼 IGN이 끊겨도, MCU가 INHIBIT을 0으로 만들기 전까지 RM이 꺼지지 않음  
이게 필요한 이유는 안정성 떄문, 갑작스럽게 IGN이 끊겼을 때 메모리와 관련된 동작이 수행중이었다면 에러가 발생할 수 있기때문에 IGN이 끊겨도 전원이 갑자기 꺼지지 않도록 해줌

CAN통신을 통해 Network Message를 보내 전원을 끄거나 켜진 상태로 유지하는 것

- selective sleep
- selective wakeup (꺼져 있다가 CAN 신호를 받으면 켜지는 것, 다른 CAN 트랜시버를 사용하므로 비용이 오름)

## FLS (시험문제)

EEPROM을 쓸 수는 있는 것 = Emulating  
Flash memory: 싸고 빠르지만, Write를 Page단위로만 할 수 있다.

- PFlash: 코드가 들어감, 2MB
- DFlash: 데이터가 들어감, 128KB

Flash memory에서 메모리에 값을 쓰고 지울 떄, EEPROM과 달리 값을 바로 수정하는 것이 아니라, 새로운 값을 입력하고 이를 최신값이라고 표시하는 방식임.  
ex) 0: 1234, 0: 5678(v)

메모리에 값을 쓰고 지우는 과정에서 전원이 꺼지는 경우 값을 지우기만하고 입력하지 않는 경우가 생김, 이런 일이 반복되다보면, 결국 메모리를 모두 사용하게 되고, 지워져서는 안될 데이터가 지워지는 경우도 발생, 따라서 이를 방지하기 위해 flash memory를 여러개의 sector로 나누는 방식을 사용함

sector가 많을 수록 쓸 수 있는 데이터는 많지만, sector를 교체하는데 비용이 많이 든다.

sector change시에 유효한 데이터만 옮기는 것 = GC

### FeeGcRestart

sector에 유효한 값을 옮기는 GC과정에 꺼지는 경우, 언젠가는 GC를 다시 진행해야하는데 그 시점을 뜻하는 옵션 (Init, rewrite)

- init: 시작할 떄 좀 느려질 수 있음
- rewrite: 종료할 때 좀 느려질 수 있음

### FeeUnConfigBlock

App에서 erase를 하면서 사용하지 않는 configuration을 지우는데, 이 과정에서 Boot에서 사용중인 config값일수도 있으므로 이 config값을 그냥 둘지, 지울지를 결정하는 옵션

### FeeThresholdValue

sector change시에 GC하는 도중에 전원이 꺼지면, 바꾸려고 했던 값을 잃어버림.  
이를 방지하기 위해서 이전 sector에 미리 바꿀 값을 적어놓고, sector change를 진행하는 것.  
이떄 그 값들을 얼마나 저장할 것이지 정하는 값.

공고가 제너럴하다고해서 이력서도 그러면 X  
키워드를 넣어야 함.

# SPI

한번에 하나의 주변장치와 데이터를 교환

통신 종류: I2C, CAN, Uart, USB, Ethernet

### I2C vs SPI

SPI가 I2C보다 훨씬 빠름  
SPI는 핀4개를 써야하지만, I2C는 2개만 써도 된다.

SPI를 2개 사용하면, 핀 8개를 써도 되고, CS(Chip Select)를 통해 어떤 SPI가 사용될지 결정하는 방식으로 핀 5개만 사용해도 된다.

### SPI는 무조건 교환

데이터를 받을 때도 더미 데이터를 보내야 하고, 데이터를 줄때도 더미 데이터를 받아야 함.  
MISO: Mater Input Slave Output
MOSI: Master Output Slave Input

### p.76

CS: Chip Select, 칩이 하나 늘어날때마다 함께 늘어남  
SPC: Clock  
SDI, SDO: Data Input, Data Output

### p.77

SpiTransferStart: MSB, LSB 중 어떤 것부터 송신할지

### p.78

센서와 잘 통신되고 있는지 확인하는 용도로 사용하기도 함

command, adrress, value (Code에서의 순서는 리틀엔디안, 빅엔디안에 따라 다를 수 있음)  
bit 0: read인지 write인지 (1이면 read, 0이면 write)  
bit 1 - 7:  
bit 8 - 15:

### p.79

REG_VALUE_AXIS6_WHO_AM_I: 0x6B

### p.81

BDU: Block Data Update, Data를 모두 Read하기 전까지는 Update하지 않는 옵션  
이를 설정하지 않으면, 값을 2Byte씩 읽기 때문에 로우 비트를 읽는 도중에 하이 비트가 변경되어 이상한 값이 읽히는 경우가 있음.

ex) 00000000 [0000000] -> 값변경됨 [11111111] 00000000 -> 읽힌 값: 11111111 00000000

### p.82

ODR: Output Data Rate  
1ms에 한번씩 데이터를 읽어간다.  
G_FS = +- 125dps (이 값이 크다고 좋은게 아님, 해상도가 떨어짐)

### p.84

Physical value: factor와 offset을 계산하여 실제 값을 구한 것

### p.90

NBT: 어느 타이밍에 값을 읽을지 (1초동안 값이 1이라면, 그 중 어느 지점에 값을 읽을지)  
Sampling point position: 80이면 80%지점에서 읽으면 된다.  
SYNC_SEG: 싱크 맞추는 용도, 항상 1

### p.92

NBT가 20이고, Sampling point position이 80이므로, PHASE_SEG2는 자동으로 4가 된다. (20 \* 0.2)

SYNC_SEG는 1 고정, 따라서 가운데 있는 PROP_SEG + PHASE_SEG1는 15

40MB(MHz) = cristal

### p.94

CanBaudRateClkSelExtOsc: CAN외부 오실레이터 크리스탈 직접 값을 가져와 쓰겠다.

### p.95

1. PROP_SEG: 네트워크 신호 지연 보상, 신호가 전송될 때 지연되는 것을 보상
2. PHASE_SEG: 에지 위상 오류 보상, 외란으로 인한 오류 보상

### p.96

RECEIVE가 먼저, TRANSMIT하면 변경할 수 없음.  
바꾸려면 RECEIVE로 바꾸고 다시 해야함

### SPiCsPolarity

High일떄 선택일지, Low일때 선택일지.  
Slave가 결정, Slave는 개발자가 설정할 수 없기 떄문

### p.92

- CAN통신의 길이 = Bit Time
- 이를 Nominal Bit Time으로 나눔
- SYNC_SEG: 싱크 맞추는 용도, 항상 1
- PROP_SEG + PHASE_SEG1 = 15
  - PROP_SEG: 트렌시버가 받고 보내는데 걸리는데 HW적으로 걸리는 시간 + CAN 라인의 길이에 따른 시간
  - PHASE_SEG1: 위상 오류 보상

## CAN

PHY_REQ: 특정 제어기에 명령을 내리는 것  
FUN_REQ(Functional): 모든 제어기에 명령을 내리는 것  
메세지는 시그널의 집합  
시그널은 비트단위로 할 수 있음

CAN통신의 주기 메세지의 가장 짧은 주기는 10ms  
8비트짜리 1개 HS CAN 기준으로 2.5%임, 따라서 최대 40개까지 올릴 수 있지만, 보통 60% 정도로 관리함

### E2E

CRC와 더불어 정합성 평가에 사용

# Watch Dog

CPU가 작동하지 않을 경우 강제로 리셋시키는 기능을 한다.  
때문에 메인 프로그램이 운용중인 CPU와 별개의 회로에서 작동함

internal(비용이 저렴함), external (보통 MCU에 전원을 공급해주는 레귤레이터에 사용)

# 정리
1. HelloWorld를 통한 시작주소 체크
2. EBTresos를 활용한 MCAL프로그래밍 stack: ADC, SPI, Port, DIO, FLS, FEE, CAN, XCP
3. 오실레이터 클럭, 칩선택 
4. 인피니온에서 제공해주는 엑셀을 통해 값을 계산하여 EBTresos에 넣음
5. GTM 80MHz 설정
6. 이를 통해 GPT설정, 목표는 1
7. INHIBIT을 통해 종료를 기다리는 이유, DTC가 뜨는 경우 스냅샷데이터를 남기는데 이 크기가 커서 섹션(섹터) 체인지가 발생할 수 있음, 따라서 종료시에 이를 저장함
8. DFlash를 활용하여 EEPROM처럼 사용하기 위해 에뮬레이팅 해봄 FLS(섹터를 몇개로 나눌 것인지), FEE(실습에 사용한 칩에는 없으므로 에뮬레이팅해서 사용)
9. SPI, Chip간 통신, CAN통신과 SPI통신. 4개의 핀 각각 CAN, SDI, SDO, SPC
10. SPI를 통한 센서 운용, 어떤 센서? STmicro의 6축센서, 몇개의 컨트롤 레지스터와 데이터를 읽어봄, 
11. CAN, 오실레이터로부터 클락을 바로 받아서 사용, 40MHz, NBT설정 500kbps, 샘플링포인트 80%, PROP_SEG = 4, PHASE_SEG1 = 11, PHASE_SEG2 = 4(샘플링포인트가 80퍼라서)
12. 트랜시버의 딜레이 시간, CAN 라인의 길이를 통한 대략적인 계산
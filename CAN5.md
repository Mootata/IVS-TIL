# Autonotie Ethernet

ADAS의 vision, radar 등의 센서로 인해 데이터 양이 증가하면서, CAN 통신만으로는 부족하여 도입

## Net Data Rate

CAN의 경우 우선순위대로 처리하기 때문에 충돌시 큰 문제가 없지만, Ethernet의 경우는 충돌하면 새로운 data를 전송한다.  
이로인한 손실이 대략 20%정도기에 속도가 125MHz라고 한다면, 실제로는 100MHz정도.

동시에 양방향으로 신호를 보낼 수 있는 것이 Full Duplex, 일방향은 Half Duplex  
Full Duplex의 경우 동시에 보낼 때 충돌이 발생할 수 있으므로, 시분할 방식을 통해 이를 조절함

## BroadR-Reach

### 100Base-TX(Fast Ethernet)

송신과 수신선을 따로 쓰는 uni-directional

### 1000Base-T

송신과 수신선을 하나로 쓰는 bi-directional

# FlexRay

동시에 여러 노드가 송신하면, 합선이 발생하므로 이를 방지하기 위해 각 노드마다 정해진 시간에만 송신할 수 있도록 제어함.  
이때, 제어만할 뿐 송신자체가 막힌것은 아니기 때문에 에러로 인한 충돌을 막기 위해 타임 정보만을 가진 Bus Guardian를 통해 정해진 시간에 정해진 노드에만 송신을 허용하게 함으로써 제어함


# SENT


# Reliability and AEC-Q100
- functional safty: 설계는 잘됐지만, 실패했을 때를 대비해두는 것 Fail Safe
- Reliability: 물리적으로 견딜 수 있는지

# CISPR


# Power Semiconductor

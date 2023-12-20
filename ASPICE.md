# A-SPICE

MSDP 만도 개발 프로세스
ASPICE는 SOP까지,

### ISO 26262

기능 안전

### SIO/SAE 21434

전지전자 시스템 보안 개발

### A-SPICE 주요 사항

1. Traceability (Consistency) \*중요
   - 개발 산출물의 추적(예. 고객요구사항 ~ 시스템TC)
   - 활동의 추적 (예. 계획-산정-일정-실적-확인-재 산정-...)
2. Strategies
   - PDCA(Plan-Do-Check-Act) cycle
   - 활동 (예. 산정, 검토, 시험 등) 수행 전략
     - Plan을 수립하기 위한 전략
     - Plan을 Do, Check, Act하기 위한 전략
3. Guideline
   - 방법
   - 도구
   - 문화

### Process assessment model

평가 모델의 요소: Process, Capability Scale

CL1 수준 수행을 평가 = Performance Indicator  
CL2 이상 수준 역량을 평가 = Capability Indicator

#### WVS의 실행 주기는 모니터링 수준에 맞춘다.

## A-SPICE

시작  
Stakeholder (이해관계자)

- 개발자
- 고객
- 마케팅, 영업

##

고객의 요구사항이 디테일할 경우 Software requirements로 바로 추적관계를 연결할 수 있다.

시스템 아키텍쳐: 동적인 설계와 정적인 설계가 필요함.
특정 기능을 구현하기 위한 내용 = Dynamic Behavier  
문서를 작성할 땐, 내부 구조를 모른다고 생각하고 작성. (black box)  
\*\* black box, end to end  
시스템 아키텍쳐나 소프트웨어 아키텍쳐할 때나 알고 작성한다.  
상위단계가 더 디테일하고, 하위가 추상적이면 조정가능  
완벽할 수는 없으므로, 하위 단계에서 작성이 힘들어질 경우, 구조를 모두 수정하거나, 상위 단계를 수정할 수 있다.(절차에 맞게)  
소프트웨어 레벨의 요구사항의 구분은 ? 시스템 레벨에서와 안에 담기는 내용은 동일함.  
unit은 소스코드라고 보면 된다.

change requests = 요구사항의 변경이 일어났을 떄, 해당 사항을 개발하기 위해 하나의 작은 V가 만들어지기도 함

소프트웨어 리콰이어먼츠에서 시스템 리콰이어먼츠, 소프트웨어 유닛츠로 튀는 선:  
설계구조에 따라서 생략가능 (Redundancy)  
요구사항이 너무 디테일하면 좋지 않음, 설계 원칙에 따라 디테일해야함  
실무에서는 시스템 리콰이어먼츠에서 요구사항이 너무 디테일하면, 인터페이스 관련된 것은 시스템 아키텍쳐에 넘겨주고, 소프트웨어 리콰이어먼츠로 넘긴다.

## SYS

### SYS.2

communicate agreed xxx 관련자가 추적 연결된 관련자들과 검토 내가 수행한 BP에 해당하는 내용들을 담은 문서를 가지고 BP7번까지 담은 문서를 가지고 BP8에서 추적 연결된 관련자들과 검토
좌측 사이드에서 단 한명만 참석해야한다면, 오른쪽 검증쪽 인원이다.

BP1: 기능적, 비기능적 요구사항 작성 (비기능 요구사항에 포함되는 것 체크 외울 필요는 없고, 느낌만 기능성, 신뢰성, 효율성, 유지보수성, 보안성, 호환성, 이식성, 사용성) 실무적으로는 릴리즈 플랜과 연관성을 맞춰야 함.  
BP2:

BP3: 분석단계, 빠진 것이 없는지, 요구 사항 속성에 담길것이 다 담겼는지, 검토와 유사, 요구사항 분석서  
[외워야 함 ensure = correctness, technical feasibility, 가장 중요한 factor는 verifiability | PM과의 커뮤니케이션이 필요한 부분 리스크 식별의 소싱(원인)이 될 수 있다. impact on cost, scedule and the technical impact]  
BP4: 외부인터페이스 리콰이어단에는 내부 인터페이스는 없다고 생각(black box 내부 인터페이스는 아키텍쳐부터 등장)  
BP5: verification을 챙기기 위한 검증의 기준,  
BP6: 양방향 추적성  
BP7:

### SYS.3 (System Architectural Design)

HSI(Hardware Software Interface)  
소프트웨어 통합은 유닛통합 1차, 컴포넌트 2차, Seguence, Activity, Statemachine  
BP1:  
BP2:
BP5: 한번에 그려지지 않음, 대안 평가, 대안 평가를 하는 방법 여러가지 왜냐? 플랫폼 아키텍쳐를 차용하는 경우에도 대안평가를 생략할 수 없음. 대안평가는 꼭 해야한다. 대안이 꼭 여러개일 필요는 없음. 하나라도 적절성 평가를 했다면 대안 평가로 볼 수 있다.  
BP6:

## SWE

### SWE.2

BP4: Operating environment  
BP5: 사용량에 적힐 수 있는 것 4가지 자원 사용량 목표치에 해당하는 것은 ? \* RAM, ROM, EEPROM, Data Flash, CPU load 이런 자원 사용량을 어디에 써야하나 ?소프트웨어 아키텍쳐 디자인 문서에 작성해야한다  
시뮬레이션 환경에서 검증하거나 통합 테스트에서 검증해도 된다. (전체, 컴포넌트 단에서의 체크)

### SWE.3

소스코드 만들기 전 설계단에서 최대한 디테일하게 설계하는 과정 구현에 필요한 모든 정보가 다 담겨야 한다. 모든 유닛에 대한 정의 컴포넌트를 기반으로  
BP4: interoperability, interaction, criticality, technical complexity, risks and testability

### SWE.4

최종 말단의 시험이 validation, 그 외 verification (ex. 2티어 기업에서 SW를 완성하고 1티어 기업에 보내면, 1티어 기업에서는 system 아키텍쳐 단에서 테스트 하는데, 이런 경우도 validation)  
verification = code review, analysis, test

## V&V Methods (Validation and Verification)

룰체크는 정적분석(coding standard)  
(Peer or Verification) review (밑으로 갈수록 포멀), 검토기법을 정했다면, 모든 검토를 해당 기법으로 해야할 필요는 없고, 최소 한번만 하면 된다.

- desk check
- walkthrough: 역할이 부여될 필요는 없음
- inspection: 사전검토 필수, 검토시 참여인원은 모두 역할이 있어야 함, 작성자가 발표자나 서기가 되서는 안됨
- joint review:

## 테스트

테스트 플랜에 작성되어야 하는 내용

- 테스트 수행 방법은 ?
- 테스트 케이스 설계 기준은 ?
- 테스트 시작 조건 / 중단 조건 / 재시작 조건은 ?
- 회귀 테스트 수행 기준은 ?
- 회귀 테스트 수행 범위는 ? (테스트 케이스 선택 기준은 ?)
- 테스트 완료 기준은 ?
- 테스트 환경은 ?
- 회귀 테스트
  - 어디로 돌아갈 것인지 ?

1단계 유닛간의 통합  
2단계 컴포넌트간의 통합

시험동향 : 관리 제어 30%, 엔지니어링 70% ( 추적관계 35% )
software unit verification

- static verification
  - code review
  - static analysis
- dynamic verification
-

## SWE.5

BP5: 릴리즈 플랜에 따라서.  
BP9: 해당 테스트의 끝, 다음 테스트의 시작점이 되는 부분 summary

## SWE.6

# 연습 문제

1. A-SPICE의 풀네임
2. 다음 중 VDA scope에 포함되지 안흔 것은 ? 2개

13: 3  
14: process quality, process quality  
15: 3  
16: 2  
17: False  
18: Plan - Do - Check - Act  
19: 3  
20: 3, problem을 구성하는 4가지 요소 = issue, review defect, test defect, NC  
21: 2, consistency, integrity = configuration management
22: Change Control Board (CCB)
23: 2
24: 2
25: 3

## MAN.3

Life Cycle은 고객에게 맞춤  
estimation

- 시간 계산 = delphi 사람들이 모여 시간을 정하는 것
- WBDelphi = 전문가들이 모여 시간을 정하는 것

WBS

- 선행관계 (dependency)
- 시간 (Man Day)
- 시간
- 시작
- 완료
- 산출물

## ACQ.4

하드웨어 전량 외주, 프로젝트 팀원중 일부 아웃소싱, 팀원 역량평가를 할 때, 역량평가 대상의 범위는 어디까진가 ?

1. 자사 팀원만
2.
3. 인력 소싱과 우리 팀원 O
4. 모두 다

## SUP.8
무결성(integrity)

## SUP.9
change request 발생: , 고객의 요구사항 변경  
Risk는 아직 발생하지 않은 문제이기 떄문에 PRM에서 다루지 않음 (Risk는 MAN.3에서 한다.)  
양방향 추적성과 일관성이 우선순위 설정에서 크리티컬하게 중요한 것은 아님  
승인을 하느냐 마냐, CCB를 하냐 마냐  
Change Control Board: 변경 요청에 대한 최종 의사결정  

## A-SPICE Capability Level (CL, 역량 수준)
Lv.2: Managed, Performance management, Work product management


# 정리
2.1 performance MAN.3  
CL2 2.2.1 ~ 4  

harrypark@sol-link.com
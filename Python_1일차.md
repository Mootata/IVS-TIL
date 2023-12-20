### Jupyter notebook

1. Command mode(파랑)

   - 셀 자체에 명령, 셀을 추가, 삭제, 이동...
   - ESC, 셀 바깥쪽 클릭을 통해 가능
   - a(bove): 현재 셀 위에 셀 추가
   - b(elow): 현재 셀 아래에 셀 추가
   - x: 현재 셀 자르기, 삭제 대용으로 사용 가능
   - h: 단축키 도움말

2. Edit mode(초록)
   - 셀 안에 코드나 문서를 작성
   - 셀 단위로 실행 (Shift + enter)

## Pandas

### Series

- 1차원 자료구조
- 구성요소 2개: index, values
- 슬라이싱 가능, 인덱스 설정시 딕셔너리와 같이 키를 통해 밸류 접근 가능

```python
import pandas as pd

math = [90, 91, 89, 90, 92]

print(pd.Series(math, index=['A', 'B', 'C', 'D', 'E']))
ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
A  90
B  91
C  89
D  90
E  92


pd.Series(math, index=['A', 'B', 'C', 'D', 'E']).sort_values()
# sort_values()의 옵션 중, ascending 기본은 True 오름차순임 false는 내림차순
ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
C  89
A  90
D  90
B  91
E  92


math_sr = pd.Series(math, index=['A', 'B', 'C', 'D', 'E'])
math_sr[math_sr > 90]
ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
B  91
E  92
dtype: int64


math = [90, 91, 89, 90, 92]
eng = [92, 90, 91, 89, 91]

math_sr = pd.Series(math, index=['A', 'B', 'C', 'D', 'E'])
eng_sr = pd.Series(eng, index=['A', 'B', 'C', 'D', 'E'])

print(math_sr + eng_sr) # Series끼리는 같은 인덱스끼리 사칙연산이 가능
print(maht_sr + 100) # Series와 상수의 연산은 모든 값에 적용된다.
ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
A  182
B  181
C  180
D  179
E  183

A  192
B  191
C  189
D  190
E  192

print(math_sr > 90)
print(math_sr[math_sr > 90])
ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
A  False
B  True
C  False
D  False
E  True

B  91
E  92
```

### DataFrame

- 2차원 자료구조
- 구성요소 3개: column, index, values
- 순서있음 => 행방향
- 데이터로의 접근은 컬럼을 가져옴. (not index)

```python
import pandas as pd

math = [90, 91, 89, 90, 92]
eng = [92, 90, 91, 89, 91]
kor = [90, 92, 90, 91, 89]

temp = {'math': math, 'eng': eng, 'kor': kor}

pd.DataFrame(temp, index = ['A', 'B', 'C', 'D', 'E'])
ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

   math	eng	kor
A	90	   92	   90
B	91 	90 	92
C	89 	91 	90
D	90	   89 	91
E	92	   91 	89


grade_df[['math', 'eng']]
ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
   math	eng
A	90    92
B	91    90
C	89    91
D	90    89
E	92    91


grade_df.loc['A']
ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
math  92
eng   91
kor   89
Name: A, dtype: int64


grade_df.loc['A', 'math']
# df에서 데이터를 덮어 씌울때는 위처럼 해야함
# grade_df.loc['A']['math']의 경우 새로운 시리즈를 생성한 후, math의 값을 가져오는
# 방식이기 때문에 grade_df의 값이 바뀌지 않음
ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
90


grade_df.iloc[-1]
# 인덱스 값(좌표)을 기준으로 접근
ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
math  90
eng   92
kor   90
Name: E, dtype: int64


grade_df.iloc[:2, :2] # [행방향 슬라이싱, 열방향 슬라이싱]
ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
   math	eng
A	90	   92
B	91	   90
```

### 필터링

```python
import pandas as pd
import seaborn as sns

tip_df = sns.load_dataset('tips')

tip_df.sort_values(['tip', 'total_bill'])

tip_df[['total_bill', 'tip']].mean()

tip_df[tip_df['total_bill'] >= 10 & (tip_df['sex'] == 'Male')]

code1 = tip_df[tip_df['total_bill'] >= 10]
code2 = tip_df[tip_df['tip'] >= 2]
code3 = tip_df[tip_df['sex'] == 'Male']

# tip_df[code1 & code2 & code3]

tip_df['total_pay'] = tip_df['total_bill'] + tip_df['tip']
```

#### 엑셀

```python
raw_df = pd.read_excel(r'C:\졸업생의 진로 현황(전체).xlsx')

raw_df.columns

category = ['지역', '정보공시 \n 학교코드', '학교명', '졸업자.2', '(특수목적고)과학고 진학자.2', '(특수목적고)외고ㆍ국제고 진학자.2']

raw_df2 = raw_df[category]

raw_df2.columns = ['Region', 'Code', 'Name', 'Gradu', 'Sci', 'Frl']

raw_df3 = raw_df2.drop(0)

# isna() => == nan
raw_df3.isna().sum() # 속성별로 NaN(결측값)이 몇개인지
raw_df3[raw_df3['Region'].isna()]

raw_df3.loc[588, 'Region'] = '서울특별시 은평구'
raw_df3.loc[3011, 'Region'] = '서울특별시 강서구'

raw_df3.loc[[588, 3011]]

raw_df4 = raw_df3.dropna().copy() # 같은 부분은 메모리를 공유, 따라서 새로운 메모리에 쓰려면 copy() 사용

raw_df4 = raw_df3.dropna(subset=['Gradu']) # Gradu 속성에 NaN이 있는 컬럼만 제외


#int => int32, int65
# float => float32, float64
#날짜 => datetime
# string => object
raw_df4.dtypes

raw_df4['Gradu'] = pd.to_numeric(raw_df4['Gradu'])
raw_df4['Sci'] = pd.to_numeric(raw_df4['Sci'])
raw_df4['Frl'] = pd.to_numeric(raw_df4['Frl'])

raw_df5 = raw_df4.reset_index(drop=True) # 기존에 index라는 컬럼이 존재하면, 해당 컬럼을 삭제하고 재생성

raw_df5
```

#### 필터링, 시리즈의 연산, apply, groupby, pivot

```python
# 필터링, 시리즈의 연산, apply, groupby, pivot

#특목고 진학자 숫자
grad_df['Spc'] = grad_df['Sci'] + grad_df['Frl']

#특목고 진학률
grad_df['Spc_R'] = (grad_df['Spc'] / grad_df['Gradu'] * 100).round(2)

# 특목고 진학률이 높은 학교 TOP 20
grad_df.sort_values('Spc_R', ascending=False)[:20]

# 졸업생 숫자가 100명을 넘고, 과고, 외고 진학자가 각각 최소 1명 이상인 학교 중에서 TOP 20
con1 = grad_df['Gradu'] >= 100
con2 = grad_df['Sci'] >= 1
con3 = grad_df['Frl'] >= 1

grad_df[con1 & con2 & con3].sort_values('Spc_R', ascending=False)[:20]

# 서울특별시

for r in grad_df['Region']:
    r.split()[0] # '서울특별시' '송파구'

#apply
# 시리즈의 모든 데이터에게 똑같은 코드를 적용 (map)

grad_df['sido'] = grad_df['Region'].apply(lambda x: x.split()[0])
grad_df['gugun'] = grad_df['Region'].apply(lambda x: x.split()[1])

# 특목고 진학률을 문자로 3.85 -> '3.85%'

grad_df['Spc_R'].apply(lambda x: str(x) + '%')


# groupby
# 카테고리 데이터를 가지고 그룹핑하여 집계

# 서울의 특목고 진학률
grad_df[ grad_df['sido'] == '서울특별시']['Spc_R'].mean()


# 카테고리(지역)별 특목고 진학률
grad_df[['sido', 'Spc_R']].groupby('sido').mean()

# 결측값이 있는 열을 count하면 NaN은 집계되지 않기 때문에 조심해야 함
grad_df[['sido', 'Gradu']].groupby('sido').count()

grad_df[['sido', 'gugun', 'Gradu']].groupby(['sido', 'gugun']).sum().reset_index()


#요일별, 성별 평균 팁 집계

tip_df[['day', 'sex', 'tip']].groupby(['sex', 'day']).mean().round(2)

# 요일별 size별 평균 팁 집계
tip_df[['day', 'size', 'tip']].groupby(['day', 'size']).mean().round(2)

pd.pivot_table(tip_df, index = 'size', columns = 'day', values = 'tip')
```

### 모듈

- pandas(as pd): DF 제공
  - read_excel, header, index_col, usecols, skiprows, na_values
  - 셀병합의 경우 DF가 이상하게 나오는 경우 다음과 같은 순서로 수정
    1. column
       - 사용할 속성 추리기
       - 컬럼명 바꾸기
    2. index
       - 보통의 경우 0, 1, 2, 3 ...
       - 시계열 데이터인 경우 인덱스를 시간 형식으로 세팅
    3. value
       - 결측 데이터 체크 (빠진 데이터)
       - 데이터 타입 체크
- numpy(as np): 선형대수 등의 연산 함수 제공
- matplotlib.pyplot(as plt): 시각화
- seaborn(as sns):

### 데이터 시각화

- 갖고 있는 데이터를 이해하기 위해서, 데이터 종류에 따라 어떤 시각화를 해서 이해하는가

#### 데이터 종류

1. 카테고리
   - `DF['col'].unique()`를 통해 한줄로 간단하게 출력된다면 카테고리 데이터라고 보면 됨
2. 연속된 숫자
   - 데이터의 분포 => 히스토그램
     `plt.hist(total_df['Gradu']) \ plt.show()`

```python
big = ['서울특별시', '부산광역시', '대구광역시', '인천광역시', '광주광역시', '대전광역시', '울산광역시',
       '세종특별자치시', '경기도']

big_df = total_df[total_df['sido'].apply(lambda x: True if x in big else False)]
small_df = total_df[~total_df['sido'].apply(lambda x: True if x in big else False)] # pandas에서는 ~가 not의 의미

plt.hist(big_df['Gradu'], bins=40, edgecolor='white', alpha=0.8)
plt.hist(small_df['Gradu'], bins=40, edgecolor='white', alpha=0.8)

plt.show()
```

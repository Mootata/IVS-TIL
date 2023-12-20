#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_LOTTO_NUMBER 45
void generateLottoNumber(int lottoNum[7])
{
    srand((unsigned)time(NULL));
    for (int i = 0; i < 7; i++)
    {
        int is_exist = 1;
        while (is_exist)
        {
            lottoNum[i] = (rand() % MAX_LOTTO_NUMBER) + 1;
            printf("%d\n", lottoNum[i]);
            // 동일한 수가 없다면 Lotto Num 에 추가, 아니면 1번 반복
            for (int j = 0; j <= i; j++)
            {
                if (lottoNum[j] == lottoNum[i])
                {
                    is_exist = 0;
                    break;
                }
            }
        }
    }
}

void printResult(int lottoNum[7], int inputNum[6])
{
    //
}

int main(void)
{
    int lottoNum[7], inputNum[6];
    int equalCount = 0;
    generateLottoNumber(lottoNum);
    printf("lotto number : %d %d %d %d %d %d\n", lottoNum[0], lottoNum[1], lottoNum[2], lottoNum[3], lottoNum[4], lottoNum[5]);
    printf("bonus number : %d\n", lottoNum[6]);
    printf("\nplease input 6 number : ");
    scanf("%d %d %d %d %d %d", &inputNum[0], &inputNum[1], &inputNum[2], &inputNum[3], &inputNum[4], &inputNum[5]);
    printResult(lottoNum, inputNum);
    system("pause");
    return 0;
}

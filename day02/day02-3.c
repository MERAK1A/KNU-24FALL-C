#include<stdio.h>


int main(void)
{
    // for (int i = 0; i <= 99; i++)
    // {
    //     if ((i % 3 == 0 && i % 4 == 0 )|| i % 7== 0)
    //     {
    //         printf("%d\n", i);
    //     }
    //     }
    for (int i = 0; i <= 99; i++)
    {
        for (int j = 0; j <= 99; j++)
        {
            // i가 3과 4의 최소공배수(12)의 배수 또는 7의 배수일 때 출력
            if (j * 12 == i || j * 7 == i)
            {
                printf("%d\n", i);
                break;  //중복 출력을 피하기 위해 루프 탈출
            }
        }
    }
    

    return 0;
}

    

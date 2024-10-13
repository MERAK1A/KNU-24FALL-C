#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TOTAL_POINTS 1000000000 // 10억
#define REPORT 10000000 // 출력
#define BAR_WIDTH 50 // 진행 막대


//Monte Carlo Algorithm
int main(void)
{
    double x = 0, y = 0;   // x, y 좌표
    long long count = 0;   // 총 횟수
    long long circle = 0;  // 원 안에 들어간 점의 개수
    int percentage = 0;    // 진행률

    srand(time(NULL));

    // 몬테카를로 알고리즘
    while (count < TOTAL_POINTS) {
        //x좌표와y좌표에해당하는두개의난수를0~r 범위에서생성한다고가정하자
        x = (double)rand() / (double)RAND_MAX;
        y = (double)rand() / (double)RAND_MAX;

        //이때ଶଶ이면해당좌표를갖는점은원안에있다고할수있다.(x^2 + y^2 <= 1)
        if (x * x + y * y <= 1) {
            circle++;
        }

        count++;

        // 1천만 번마다 진행 상황 출력
        if (count % REPORT == 0) {
            percentage = (int)((double)count / TOTAL_POINTS * 100); // 퍼센트 계산
            double pi = 4.0 * circle / count;

            // 진행 막대 출력
            printf("%d%% 진행 : 원주율 = %.6f ", percentage, pi);
            printf("[");
            int pos = (BAR_WIDTH * percentage) / 100;
            for (int i = 0; i < BAR_WIDTH; ++i) {
                if (i < pos) printf("■");
                else printf(" ");
            }
            printf("]\n");
        }
    }

    // 최종 원주율 계산, 출력
    double final_pi = 4.0 * circle / TOTAL_POINTS;  
    printf("최종 원주율 : %.6f\n", final_pi);

    return 0;
}

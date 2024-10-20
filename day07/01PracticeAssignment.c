#include <stdio.h>

int main(void) {

    int num1 = 0;
    // 층수 입력
    printf("피라미드 층수를 입력해 주세요. : ");
    scanf("%d", &num1); 

    for (int i = 0; i < num1; i++) { 
        // 공백 출력
        for (int j = 0; j < num1 - i - 1; j++) {
            printf(" ");
        }
        // 별 출력.
        for (int k = 0; k < 2 * i + 1; k++) {
            printf("*");
        }
        printf("\n");
    }


    return 0;
}

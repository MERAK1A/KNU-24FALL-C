#include <stdio.h>

// 소수를 판별하는 함수
int is_prime(int num) {
    if (num <= 1) {
        return 0; 
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0; 
        }
    }
    return 1; 
}

int main() {
    int number;
    
    printf("정수를 입력하세요: ");
    scanf("%d", &number);
    
    if (is_prime(number)) {
        printf("%d는 소수입니다.\n", number);
    } else {
        printf("%d는 소수가 아닙니다.\n", number);
    }
    
    return 0;
}

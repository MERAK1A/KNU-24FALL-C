#include <stdio.h>


int factorial(int n) {
    if (n == 0) {
        return 1;  
    } else {
        return n * factorial(n - 1);  
    }
}

int main() {
    int number;
    
    printf("정수를 입력하세요: ");
    scanf("%d", &number);
    
    if (number < 0) {
        printf("음수는 팩토리얼을 계산할 수 없습니다.\n");
    } else {
        printf("%d! = %d\n", number, factorial(number));
    }
    
    return 0;
}

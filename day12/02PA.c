#include <stdio.h>

int solution(int n) {
    int ans = 0;
    // n이 0이 될 때까지 반복
    while (n > 0) {
        // n이 홀수인 경우
        if (n % 2 == 1) {
            ans++; // 1칸 점프 - 배터리 소모 1
            n--; // 위치 1 감소
        }
        // n이 짝수인 경우
        else {
            n = n / 2; // 순간이동은 거리 절반으로 감소, 배터리 소모 X
        }
    }
    
    return ans;
}

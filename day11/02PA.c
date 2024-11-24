#include <stdio.h>
#include <math.h>

double f(double x) {
    // f(x) = -log10(1/x) + sin(x)
    return -log10(1.0/x) + sin(x);
}

double integral(double a, double b, int n) {
    double dx = (b - a) / n;  // 구간 너비
    double sum = 0.0;
    
    // 각 구간에 대해 면적 계산 및 합산
    for(int i = 0; i < n; i++) {
        double x = a + i * dx;  // 각 구간의 시작점
        sum += f(x) * dx;       // 면적 = 높이 * 너비
    }
    
    return sum;
}

int main() {
    double a = 10.0;    // 적분 시작점
    double b = 30.0;    // 적분 끝점
    int n = 10000;      // 구간 분할 개수
    
    double result = integral(a, b, n);
    printf("적분 결과: %lf\n", result);
    
    return 0;
}
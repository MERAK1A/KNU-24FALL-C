#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main() {
    double a, b, c;
    double D, root1, root2;

    // 계수 입력
    printf("입력: a, b, c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    // 
    D = b * b - 4 * a * c;

    // 해 계산
    if (D > 0) {
        // 두 실근
        root1 = (-b + sqrt(D)) / (2 * a);
        root2 = (-b - sqrt(D)) / (2 * a);
        printf("두 실근.\n");
        printf("Root 1 = %.2lf\n", root1);
        printf("Root 2 = %.2lf\n", root2);
    } else if (D == 0) {
        // 중근
        root1 = -b / (2 * a);
        printf("중근.\n");
        printf("Root = %.2lf\n", root1);
    } else {
        // 허근
        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(-D) / (2 * a);
        printf("허근.\n");
        printf("Root 1 = %.2lf + %.2lf\n", realPart, imaginaryPart);
        printf("Root 2 = %.2lf - %.2lf\n", realPart, imaginaryPart);
    }

    return 0;
}

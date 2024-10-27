#include <stdio.h>

// 3차원 벡터를 나타내는 구조체
typedef struct {
    int x;
    int y;
    int z;
} Vector;

// 합을 계산하는 함수
Vector add(Vector v1, Vector v2) {
    Vector result;
    result.x = v1.x + v2.x;
    result.y = v1.y + v2.y;
    result.z = v1.z + v2.z;

    return result;
}

// 차를 계산하는 함수
Vector subtract(Vector v1, Vector v2) {
    Vector result;
    result.x = v1.x - v2.x;
    result.y = v1.y - v2.y;
    result.z = v1.z - v2.z;

    return result;
}

// 내적을 계산하는 함수 
int dot(Vector v1, Vector v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

// 외적을 계산하는 함수 
Vector cross(Vector v1, Vector v2) {
    Vector result;
    result.x = v1.y * v2.z - v1.z * v2.y;
    result.y = v1.z * v2.x - v1.x * v2.z;
    result.z = v1.x * v2.y - v1.y * v2.x;

    return result;
}

// 벡터 입력 함수
Vector input_vector() {
    Vector v;

    printf("벡터의 x, y, z 값을 입력하세요: ");
    scanf("%d %d %d", &v.x, &v.y, &v.z);    
    while (getchar() != '\n');
    
    return v;
}

int main() {
    Vector v1, v2;
    int option = 0;

    // 첫 번째 벡터 입력
    printf("첫 번째 벡터 입력\n");
    v1 = input_vector();

    // 두 번째 벡터 입력
    printf("두 번째 벡터 입력\n");
    v2 = input_vector();
    while (1)
    {
        printf("첫 번째 벡터 : %d %d %d\n", v1.x, v1.y, v1.z);
        printf("두 번째 벡터 : %d %d %d\n", v2.x, v2.y, v2.z);

        printf("----------------------\n");

        printf("1. 벡터의합 \n2. 벡터의 차\n3. 벡터의 내적 \n4.백터의 외적\n5. 종료\n");
        printf("----------------------\n");

        printf("명령 입력 :");

        scanf("%d", &option);

        switch (option)
        {
        case 1:{    // 벡터의 합
            Vector sum = add(v1, v2);
            printf("벡터 합: (%d, %d, %d)\n", sum.x, sum.y, sum.z);
            printf("----------------------\n");

            break;
        }
        case 2:{
            // 벡터의 차
            Vector diff = subtract(v1, v2);
            printf("벡터 차: (%d, %d, %d)\n", diff.x, diff.y, diff.z);
            printf("----------------------\n");

            break;  
        }  
        case 3:{
            // 벡터의 내적
            int dot_product = dot(v1, v2);
            printf("벡터 내적: %d\n", dot_product);
            printf("----------------------\n");

            break;    
        }
        case 4:{
            // 벡터의 외적
            Vector cross_product = cross(v1, v2);
            printf("벡터 외적: (%d, %d, %d)\n", cross_product.x, cross_product.y, cross_product.z);
            printf("----------------------\n");

            break;
        }
        case 5:{
            //종료
            printf("종료");
            return 0;
        }
    }
    }
        
    
    return 0;
}
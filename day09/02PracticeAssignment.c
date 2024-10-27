#include <stdio.h>

// 상품 정보를 담을 구조체 Product 정의
struct Product {
    int productID;       // 상품 ID
    char productName[100]; // 상품명
    int price;           // 가격
};

// 상품 정보를 출력하는 함수
void printProduct(struct Product p) {
    printf("상품 ID: %d\n", p.productID);
    printf("상품명: %s\n", p.productName);
    printf("가격: %d\n", p.price);
}

int main() {
    struct Product products[5]; // 최대 5개의 상품을 저장할 수 있는 배열
    int count = 0;              // 입력된 상품의 개수를 저장할 변수
    char choice;

    // 상품 정보 입력
    while (count < 5) {
        printf("상품 정보를 입력하세요 (%d/5):\n", count + 1);
        printf("상품 ID: ");
        scanf("%d", &products[count].productID);

        if (products[count].productID == 0){ // ID 에 0이 입력되면 종료
            break;
        }
        printf("상품명: ");
        scanf("%s", products[count].productName);
        printf("가격: ");
        scanf("%d", &products[count].price);

        
        count++; // 상품 개수 증가

        // 추가 입력 여부 확인
        if (count < 5) {
            printf("계속 입력하시겠습니까? (y/n): ");
            scanf(" %c", &choice);  // 개행문자 무시를 위한 공백
            if (choice == 'n' || choice == 'N') {
                break;  // 입력 중단
            }
        }
    }
    // 입력된 상품 목록 출력
    printf("\n입력된 상품 정보:\n");

    for (int i = 0; i < count; i++) {
        printf("\n상품 %d:\n", i + 1);
        printProduct(products[i]);
    }


    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 고객 등급 정의
typedef enum { 
    R_1 = 1, R_2, R_3, R_4, R_5 
} R;

// 고객 구조체 정의
typedef struct Customer {
    char customerName[50];
    R r;
    int order_amount;
    int point;
    struct Customer* prev;
    struct Customer* next;
} Customer;

// 리스트의 시작(head)와 끝(tail)
Customer* head = NULL;
Customer* tail = NULL;

// 새로운 고객 생성 및 우선순위에 따라 삽입
void add_customer(char* name, R r, int order_amount, int point) {
    Customer* new_customer = (Customer*)malloc(sizeof(Customer));
    strcpy(new_customer->customerName, name);
    new_customer->r = r;
    new_customer->order_amount = order_amount;
    new_customer->point = point;
    new_customer->prev = NULL;
    new_customer->next = NULL;

    // 빈 리스트 처리
    if (head == NULL) {
        head = tail = new_customer;

        return;
    }

    // 우선순위에 따른 삽입 위치 탐색
    Customer* cur = head;
    while (cur != NULL) {
        if (new_customer->r < cur->r ||  // 1. 등급이 더 높은 경우
            (new_customer->r == cur->r && new_customer->order_amount > cur->order_amount) ||  // 2. 주문량이 더 많은 경우
            (new_customer->r == cur->r && new_customer->order_amount == cur->order_amount && new_customer->point > cur->point)) { // 3. 포인트가 더 많은 경우

            break;
        }
        cur = cur->next;
    }

    // 삽입 처리
    if (cur == head) { // 맨 앞에 삽입
        new_customer->next = head;
        head->prev = new_customer;
        head = new_customer;
    } else if (cur == NULL) { // 맨 뒤에 삽입
        tail->next = new_customer;
        new_customer->prev = tail;
        tail = new_customer;
    } else { // 중간에 삽입
        new_customer->prev = cur->prev;
        new_customer->next = cur;
        cur->prev->next = new_customer;
        cur->prev = new_customer;
    }
}

// 고객 삭제
void delete_customer(char* name) {
    Customer* cur = head;

    while (cur != NULL) {
        if (strcmp(cur->customerName, name) == 0) {
            if (cur == head) {
                head = cur->next;
                if (head != NULL) head->prev = NULL;
            } else if (cur == tail) {
                tail = cur->prev;
                if (tail != NULL) tail->next = NULL;
            } else {
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
            }
            free(cur);
            printf("%s의 정보가 삭제되었습니다.\n", name);

            return;
        }
        cur = cur->next;
    }
    printf("해당 이름의 고객이 없습니다.\n");
}

// 고객 수정
void update_customer(char* name, R r, int order_amount, int point) {
    delete_customer(name);
    add_customer(name, r, order_amount, point);
    printf("%s의 정보가 수정되었습니다.\n", name);
}

// 전체 고객 출력
void print_customers() {
    Customer* cur = head;
    printf("-----------------------------\n");

    while (cur != NULL) {
        printf("이름: %s, 등급: %d, 주문량: %d, 포인트: %d\n",
               cur->customerName, cur->r, cur->order_amount, cur->point);
        cur = cur->next;
    }
    printf("-----------------------------\n");
}

// 메뉴 및 실행
void menu() {
    int choice;
    char name[50];
    int r, order_amount, point;

    while (1) {
        printf("1. 고객 추가\n");
        printf("2. 고객 삭제\n");
        printf("3. 고객 수정\n");
        printf("4. 전체 리스트 출력\n");
        printf("5. 프로그램 종료\n");
        printf("input : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("고객 이름: ");
                scanf("%s", name);
                printf("등급 (1~5): ");
                scanf("%d", &r);
                printf("주문량: ");
                scanf("%d", &order_amount);
                printf("포인트: ");
                scanf("%d", &point);
                add_customer(name, r, order_amount, point);

                break;
            case 2:
                printf("삭제할 고객 이름: ");
                scanf("%s", name);
                delete_customer(name);

                break;
            case 3:
                printf("수정할 고객 이름: ");
                scanf("%s", name);
                printf("새 등급 (1~5): ");
                scanf("%d", &r);
                printf("새 주문량: ");
                scanf("%d", &order_amount);
                printf("새 포인트: ");
                scanf("%d", &point);
                update_customer(name, r, order_amount, point);

                break;
            case 4:
                print_customers();

                break;
            case 5:
                printf("프로그램을 종료합니다.\n");

                return;
            default:
                printf("올바른 번호를 선택하세요.\n");
        }
    }
}

int main() {
    menu();
    
    return 0;
}

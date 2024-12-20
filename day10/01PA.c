#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[50];
    int score;
    struct Student* next;
} Student;

Student* head = NULL;

// 학생 노드 생성 및 점수 순서대로 삽입 (내림차순 정렬)
void ins_student(char* name, int score) {
    Student* new_student = (Student*)malloc(sizeof(Student));
    strcpy(new_student->name, name);
    new_student->score = score;
    new_student->next = NULL;

    // 리스트가 비어 있거나 새로운 학생이 가장 높은 점수를 가질 경우
    if (head == NULL || head->score < score) {
        new_student->next = head;
        head = new_student;
    } else {
        Student* cur = head;

        // 현재 노드의 점수가 새 노드의 점수보다 높거나 같을 때까지 이동
        while (cur->next != NULL && cur->next->score >= score) {
            cur = cur->next;
        }
        // 새 노드 삽입
        new_student->next = cur->next;
        cur->next = new_student;
    }
}


// 학생 노드 삭제
void del_student(char* name) {
    if (head == NULL) {
        printf("학생 정보가 없습니다.\n");

        return;
    }

    if (strcmp(head->name, name) == 0) {
        Student* temp = head;
        head = head->next;
        free(temp);
        printf("%s의 정보가 삭제되었습니다.\n", name);

        return;
    }

    Student* cur = head;
    while (cur->next != NULL && strcmp(cur->next->name, name) != 0) {
        cur = cur->next;
    }

    if (cur->next == NULL) {
        printf("해당 이름의 학생이 없습니다.\n");
    } else {
        Student* temp = cur->next;
        cur->next = cur->next->next;
        free(temp);
        printf("%s의 정보가 삭제되었습니다.\n", name);
    }
}

// 모든 학생 정보 출력
void print_students() {
    Student* cur = head;
    printf("-----------------------------\n");

    while (cur != NULL) {
        printf("%s : %d\n", cur->name, cur->score);
        cur = cur->next;
    }
    printf("-----------------------------\n");
}

// 메뉴 출력 및 선택
void menu() {
    int option;
    char name[50];
    int score;

    while (1) {
        printf("1. 학생의 성적을 입력\n");
        printf("2. 학생 정보 제거\n");
        printf("3. 프로그램 종료\n");
        printf("input : ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("학생 이름: ");
                scanf("%s", name);
                printf("%s의 성적: ", name);
                scanf("%d", &score);
                ins_student(name, score);
                print_students();
                
                break;
            case 2:
                printf("삭제할 학생 이름: ");
                scanf("%s", name);
                del_student(name);
                print_students();

                break;
            case 3:
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

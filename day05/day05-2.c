#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int stu_id;    // 학번
    char name[100]; // 이름
    int score;    // 점수
} Student; 

int main(void) {
    int N = 0;  // 학생 수
    Student* students;  // 학생 정보를 저장할 구조체 배열

    // 학생 수 입력
    printf("학생 수 입력: ");
    scanf("%d", &N);

    // 학생 수에 맞게 메모리 동적 할당
    students = (Student*)malloc(N * sizeof(Student));

    // 학생 정보 입력
    for (int i = 0; i < N; i++) 
    {
        printf("학번: ");
        scanf("%d", &students[i].stu_id);

        printf("이름: ");
        scanf("%s", students[i].name);

        printf("점수: ");
        scanf("%d", &students[i].score);
    }

    // 입력된 학생 정보 출력
    printf("\n입력된 학생 정보:\n");
    for (int i = 0; i < N; i++) {
        printf("%d %s %d\n", students[i].stu_id, students[i].name, students[i].score);
    }

    // 점수 합계, 평균, 최대값, 최소값 계산
    int sum = 0;
    float avg;
    int max = 0;
    int min = 100;

    for (int i = 0; i < N; i++) {
        sum += students[i].score;

        if (students[i].score > max) {
            max = students[i].score;
        }
        if (students[i].score < min) {
            min = students[i].score;
        }
    }

    avg = (float)sum / N;
    printf("\n최대 점수: %d, 최소 점수: %d, 평균 점수: %.2f\n", max, min, avg);

    // 할당된 메모리 해제
    free(students);

    return 0;
}


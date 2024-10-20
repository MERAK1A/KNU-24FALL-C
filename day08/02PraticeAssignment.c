#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define MAX_VALUE 20

void fillRandom(int array[SIZE][SIZE]);
void printArray(int array[SIZE][SIZE]);
void movePointer(void* array);

// 2차원 배열을 랜덤 값으로 초기화하는 함수
void fillRandom(int array[SIZE][SIZE]) {

    srand(time(NULL));
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            array[i][j] = rand() % MAX_VALUE + 1;  // 1~20 범위의 랜덤 값
        }
    }
}

// 배열을 출력하는 함수
void printArray(int array[SIZE][SIZE]) {

    printf("초기화된 배열:\n");

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%2d ", array[i][j]);
        }
        printf("\n");
    }
}
// void 포인터는 모든 타입의 주소를 저장할 수 있는 장점이 있다
// 포인터 연산을 이용해 배열을 순회하는 함수
void movePointer(void* array) {

    int index = 0;                       // 시작 위치 (0, 0)을 1차원 인덱스로 변환
    int total_size = SIZE * SIZE;        // 2차원 배열을 1차원으로 취급했을 때의 총 크기
    int value;                           // 현재 위치에서 읽어온 값
    int* int_array = (int*)array;       // void 포인터를 int 포인터로 캐스팅

    while (1) {

        value = *(int_array + index);   // 현재 위치의 배열 값을 얻음
        printf("현재 위치: (%d, %d), 값: %d\n", index / SIZE, index % SIZE, value);

        // 배열 값만큼 이동, 인덱스는 1차원 배열처럼 취급
        if (index + value < total_size) {
            index += value;              // 값을 더해 이동
        } else {
            printf("더 이상 이동할 수 없습니다.\n");
            
            break;                       // 더 이상 이동할 수 없을 때 종료
        }   
    }

    printf("최종 위치: (%d, %d)\n", index / SIZE, index % SIZE);
}

int main(void) {

    int array[SIZE][SIZE];              // 10x10 배열 선언

    fillRandom(array);                  // 배열을 랜덤 값으로 초기화
    printArray(array);                  // 배열 출력
    movePointer(&array[0][0]);         // 포인터를 사용해 배열 순회


    return 0;
}


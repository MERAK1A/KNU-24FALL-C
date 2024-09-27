#include <stdio.h>
#include <stdlib.h>

int main(void){

    
    int N = 0;
    int* stu;
    char** name;
    int* score;
    
    printf("학생 수 입력 : ");
    scanf("%d", &N);

    stu = (int*)malloc(N * sizeof(int));
    score = (int*)malloc(N * sizeof(int));
    name = (char**)malloc(N * sizeof(char*));
    //char* -> name = (char*)malloc(N * 100 * sizeof(char))

    for (int i = 0; i < N; i++){

        name[i] = (char*)malloc(100 * sizeof(char*));    
    }
    
    for (int i = 0; i < N; i++){

        printf("학번:") ;    
        scanf("%d", &stu[i]);

        printf("name:");
        scanf("%s", name[i]);
        //scanf("%s", name + (100 * i))

        printf("score:");
        scanf("%d", &score[i]);
    }

    for (int i = 0; i < N; i++){

        printf("%d %s %d\n", stu[i], name[i], score[i]);
        // printf("%d %s %d\n", stu[i], name + (100 * i), score[i]);
    }

    int sum = 0;
    float avg;
    int max = 0;
    int min = 100;
    for (int i = 0; i < N; i++)
    {
        sum += score[i]; 

        if (score[i] > max)
        {
            max = score[i];
        }
        if (score[i] < min)
        {
            min = score[i];
        }
    }
    avg = (float)sum / N ;
    printf("최대 : %d, 최소 : %d ,평균 : %0.2f", max, min, avg);


    free(stu);
    free(name);
    free(score);


    return 0;
}


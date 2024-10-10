#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Students {

    int snum;
    char name[100];
    int score;
};

int main(void){

    int N;
    struct Students person[2];

    person[0]. snum = 1111;
    person[0].name = (char*)malloc(sizeof(char) * 10);
    strcpy_s(person[0].name, 10, "chulsu");
    person[0].score = 100;

    printf("");



    
    return 0;
}


#include <stdio.h>
#include <string.h>

int main(void) {
    char str[100];  // 문자열 저장을 위한 배열
    char *ptr;      // 포인터 변수
    int valid = 1;  // 유효한 입력인지 확인하는 변수

    printf("문자열을 입력하세요.: ");
    fgets(str, sizeof(str), stdin);  // 사용자로부터 문자열 입력 받기

    // fgets는 개행 문자를 포함하므로, 이를 제거
    str[strcspn(str, "\n")] = '\0';

    // 입력된 문자열이 영어 알파벳인지, 공백이 포함되어 있는지 확인
    for (int i = 0; i < strlen(str); i++) {
        // 공백 발견시 vaild 값을 0으로 변경
        if (str[i] == ' ' || str[i] == '\t') {
            valid = 0;  

            break;
        }
         // 영어 알파벳이 아닌 문자 발견시 valid 값을 0으로 변경
        if (!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))) {
            valid = 0; 

            break;
        }
    }

    if (!valid) {
        printf("오류: 영어 알파벳만 입력 가능하며 공백은 포함할 수 없습니다.\n");

        return 1;  // 프로그램 종료
    }

    // 포인터가 문자열의 마지막 문자를 가리키도록 설정
    ptr = str + strlen(str) - 1;

    printf("역순 문자열: ");
    // 포인터를 사용해 역순으로 문자 출력
    while (ptr >= str) {
        printf("%c", *ptr);
        ptr--;  // 포인터를 이전 문자로 이동
    }
    
    printf("\n");


    return 0;
}

#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>

int main(void) {
    wchar_t str[100];  // 넓은 문자 저장을 위한 배열
    wchar_t *ptr;      // 포인터 변수

    // 로케일 설정 (유니코드 입력/출력을 위해 필수)
    setlocale(LC_ALL, "");

    wprintf(L"문자열을 입력하세요: ");
    wscanf(L"%ls", str);  // 사용자로부터 넓은 문자열 입력 받기

    // 포인터가 문자열의 마지막 문자를 가리키도록 설정
    ptr = str + wcslen(str) - 1;

    wprintf(L"역순 문자열: ");
    // 포인터를 사용해 역순으로 문자 출력
    while (ptr >= str) {
        wprintf(L"%lc", *ptr);
        ptr--;  // 포인터를 이전 문자로 이동
    }
    wprintf(L"\n");

    return 0;
}

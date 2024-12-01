#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// topping_len은 배열 topping의 길이입니다.
int solution(int topping[], size_t topping_len) {
    int answer = -1;  // -1로 초기화 
    // 각 부분의 토핑 개수를 저장할 배열 선언
    int left[10001] = {0};    // 왼쪽 부분의 토핑 개수 배열
    int right[10001] = {0};   // 오른쪽 부분의 토핑 개수 배열
    int left_count = 0;       // 왼쪽의 고유한 토핑 종류 수
    int right_count = 0;      // 오른쪽의 고유한 토핑 종류 수
    // 처기에 모든 토핑을 오른쪽에 배치
    for(int i = 0; i < topping_len; i++) {
        if(right[topping[i]] == 0) {
            right_count++;
        }
        right[topping[i]]++;
    }
    // answer를 0으로 재설정
    answer = 0;
    // 하나씩 왼쪽으로 이동하며 확인
    for(int i = 0; i < topping_len; i++) {
        // 왼쪽에 토핑 추가
        if(left[topping[i]] == 0) {
            left_count++;
        }
        left[topping[i]]++;
        // 오른쪽에서 토핑 제거
        right[topping[i]]--;
        if(right[topping[i]] == 0) {
            right_count--;
        }  
        // 양쪽의 토핑 종류 수가 같으면 answer 증가
        if(left_count == right_count) {
            answer++;
        }
    }
    
    return answer;
}
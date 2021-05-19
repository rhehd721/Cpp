#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* number, int k) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc(1);
    return answer;
}

int main() {

    const char* number;
    int k;

    number = "1924";
    k = 2;
    solution(number, k); // return "94"

    number = "1231234";
    k = 3;
    solution(number, k); // return "3234"

    number = "4177252841";
    k = 4;
    solution(number, k); // return "775841"


    return 0;
}
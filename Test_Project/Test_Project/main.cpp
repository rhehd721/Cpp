#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
char* solution(const char* number, int k) {
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
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
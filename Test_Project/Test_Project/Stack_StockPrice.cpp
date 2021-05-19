//#include <stdio.h>
//#include <stdbool.h>
//#include <stdlib.h>
//
//// prices_len은 배열 prices의 길이입니다.
//int* solution(int prices[], size_t prices_len) {
//    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
//    int* answer = (int*)malloc(sizeof(int)*prices_len);
//
//    for (int idx = 0; idx < prices_len; idx++) {
//        int tem = 0;
//        for (int idx2 = idx; idx2 < prices_len; idx2++) {
//            if (idx2 == idx) { continue; }
//
//            tem++;
//            if (prices[idx] > prices[idx2]) {   // 가격이 하락했다면
//                break;
//            }
//        }
//        answer[idx] = tem;
//    }
//
//    for (int idx = 0; idx < prices_len; idx++) {
//        printf("%d ,", answer[idx]);
//    }
//    return answer;
//}
//
//int main() {
//    int prices[5];
//    prices[0] = 1;
//    prices[1] = 2;
//    prices[2] = 3;
//    prices[3] = 2;
//    prices[4] = 3;
//
//    // printf("%d", sizeof(prices) / sizeof(int));
//    
//    free(solution(prices, sizeof(prices) / sizeof(int) )); // [4, 3, 1, 1, 0]
//
//    return 0;
//}
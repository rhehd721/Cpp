//#include <stdio.h>
//#include <stdbool.h>
//#include <stdlib.h>
//
//// prices_len�� �迭 prices�� �����Դϴ�.
//int* solution(int prices[], size_t prices_len) {
//    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
//    int* answer = (int*)malloc(sizeof(int)*prices_len);
//
//    for (int idx = 0; idx < prices_len; idx++) {
//        int tem = 0;
//        for (int idx2 = idx; idx2 < prices_len; idx2++) {
//            if (idx2 == idx) { continue; }
//
//            tem++;
//            if (prices[idx] > prices[idx2]) {   // ������ �϶��ߴٸ�
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
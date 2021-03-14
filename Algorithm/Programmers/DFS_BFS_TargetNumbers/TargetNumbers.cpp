// 주어지는 숫자의 개수는 2개 이상 20개 이하입니다.
// 각 숫자는 1 이상 50 이하인 자연수입니다.
// 타겟 넘버는 1 이상 1000 이하인 자연수입니다.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;

    while(1){   // 모든 경우의 수를 확인할때까지 
        for ( int Num : numbers){

        }
    }



    return answer;
}

int main(){
    vector<int> numbers;
    int target;

    numbers.push_back(1);
    numbers.push_back(1);
    numbers.push_back(1);
    numbers.push_back(1);
    numbers.push_back(1);
    target=3;
    solution(numbers, target);  //	5
}
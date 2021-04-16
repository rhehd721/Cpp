// 제한사항
// 과학자가 발표한 논문의 수는 1편 이상 1,000편 이하입니다.
// 논문별 인용 횟수는 0회 이상 10,000회 이하입니다.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;


    cout << answer << endl;
    return answer;
}

int main(){
    vector<int> citations;
    citations.push_back(3);
    citations.push_back(0);
    citations.push_back(6);
    citations.push_back(1);
    citations.push_back(5);

    solution(citations);    // 3
}
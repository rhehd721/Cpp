// 제한사항
// absolutes의 길이는 1 이상 1,000 이하입니다.
// absolutes의 모든 수는 각각 1 이상 1,000 이하입니다.
// signs의 길이는 absolutes의 길이와 같습니다.
// signs[i] 가 참이면 absolutes[i] 의 실제 정수가 양수임을, 그렇지 않으면 음수임을 의미합니다.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;

    for (int i(0); i < absolutes.size(); i++){
        if(signs[i]){   // 참이면 실행 즉, 양수면
            answer += absolutes[i];
        }
        else{
            answer -= absolutes[i];
        }
    }

    cout << answer << endl;
    return answer;
}

int main(){

    vector<int> absolutes;
    absolutes.push_back(4);
    absolutes.push_back(7);
    absolutes.push_back(12);
    vector<bool> signs;
    signs.push_back(true);
    signs.push_back(false);
    signs.push_back(true);
    solution(absolutes, signs);  // 9



    absolutes.clear();
    absolutes.push_back(1);
    absolutes.push_back(2);
    absolutes.push_back(3);
    signs.clear();
    signs.push_back(false);
    signs.push_back(false);
    signs.push_back(true);
    solution(absolutes, signs);  // 0

}
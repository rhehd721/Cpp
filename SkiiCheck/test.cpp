// 실패율 : 스테이지에 도달했으나 아직 클리어하지 못한 플레이어의 수 / 스테이지에 도달한 플레이어 수

// 제한사항
// 스테이지의 개수 N은 1 이상 500 이하의 자연수이다.
// stages의 길이는 1 이상 200,000 이하이다.
// stages에는 1 이상 N + 1 이하의 자연수가 담겨있다.
// 각 자연수는 사용자가 현재 도전 중인 스테이지의 번호를 나타낸다.
// 단, N + 1 은 마지막 스테이지(N 번째 스테이지) 까지 클리어 한 사용자를 나타낸다.
// 만약 실패율이 같은 스테이지가 있다면 작은 번호의 스테이지가 먼저 오도록 하면 된다.
// 스테이지에 도달한 유저가 없는 경우 해당 스테이지의 실패율은 0 으로 정의한다.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;

    int human(stages.size());
    sort(stages.begin(), stages.end());

    int end_num(stages[stages.size() - 1]);

    vector<float> result;

    int currnt(0);  // 현재 위치
    for(int idx(0); idx <= end_num; idx++){
        int win(0); // 깬 사람들
        for(int j = currnt; j < stages.size(); j++){
            if(idx == stages[j]){
                win++;
                if(idx != stages[j+1]){
                    result.push_back(win/(double)(stages.size() - currnt));
                    cout << currnt << ", " << j << endl;
                    currnt = j;
                    break;
                }
            }
        }
    }

    // int a = 1;
    // cout << a/(double)8;

    cout << "result : ";
    for (float i : result){
        cout << i << ", ";
    }
    cout << endl; 
    

    // cout << "answer : ";
    // for (int i : answer){
    //     cout << i << ", ";
    // }
    // cout << endl; 
    return answer;
}

int main(){
    int N(5);
    vector<int> stages;
    stages.push_back(2);
    stages.push_back(1);
    stages.push_back(2);
    stages.push_back(6);
    stages.push_back(2);
    stages.push_back(4);
    stages.push_back(3);
    stages.push_back(3);
    solution(N, stages); // [3,4,2,1,5]
    
    stages.clear();
    N = 4;
    stages.push_back(4);
    stages.push_back(4);
    stages.push_back(4);
    stages.push_back(4);
    stages.push_back(4);

    solution(N, stages); // [4,1,2,3]

}
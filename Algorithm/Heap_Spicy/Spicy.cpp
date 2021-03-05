// 제한 사항
// scoville의 길이는 2 이상 1,000,000 이하입니다.
// K는 0 이상 1,000,000,000 이하입니다.
// scoville의 원소는 각각 0 이상 1,000,000 이하입니다.
// 모든 음식의 스코빌 지수를 K 이상으로 만들 수 없는 경우에는 -1을 return 합니다.

// 섞은 음식의 스코빌 지수 = 가장 맵지 않은 음식의 스코빌 지수 + (두 번째로 맵지 않은 음식의 스코빌 지수 * 2)

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    int NewScoville = 0;

    priority_queue < int, vector<int> , greater<int> > pqscovile;

    for (int i : scoville){
        pqscovile.push(i);
    }

    while(1){
        if (pqscovile.top() >= K){  // 모든 음식이 K를 넘겼을 경우
            break;
        }
        else{   // 모든 음식이 K를 넘지 못했기 때문에 새로운 음식을 만든다.
            if (pqscovile.size() >= 2){  // 섞을 음식이 남았을 경우
            NewScoville += pqscovile.top();
            pqscovile.pop();
            NewScoville += ( pqscovile.top() * 2 );    // 새로만든 스코빌 지수
            pqscovile.pop();
            pqscovile.push(NewScoville);    // 새로운 음식 추가
            ++answer;   // 음식을 섞었으므로 횟수 증가!
            NewScoville = 0;
            }
            else{   // 더이상 합성할 음식이 없으므로 -1 반환
                answer = -1;
                break;
            }
        }
    }
    cout << answer << endl;
    return answer;
}

int main(){
    vector<int> scoville;

    scoville.push_back(1);
    scoville.push_back(2);
    scoville.push_back(3);
    scoville.push_back(9);
    scoville.push_back(10);
    scoville.push_back(12);

    int K = 7;

    solution(scoville, K);   // 2
}
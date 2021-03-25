// 제한사항
// 현재 대기목록에는 1개 이상 100개 이하의 문서가 있습니다.
// 인쇄 작업의 중요도는 1~9로 표현하며 숫자가 클수록 중요하다는 뜻입니다.
// location은 0 이상 (현재 대기목록에 있는 작업 수 - 1) 이하의 값을 가지며 대기목록의 가장 앞에 있으면 0, 두 번째에 있으면 1로 표현합니다

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<  pair <int,int> > q_priorities;
    int outNum(0);
    int end(0);

    int idx(0);
    for (int i : priorities){
        q_priorities.push(pair<int,int>(idx++, i));
    }
    // cout << q_priorities.front().first << ", " << q_priorities.back().first << endl;

    while(!q_priorities.empty()){
        idx = q_priorities.front().first;
        outNum = q_priorities.front().second;
        if (idx == location){   // 이것이니?!!
            end = 1;
        }

        for (int i = 1; i < priorities.size(); i++){
            if (outNum < priorities.at(i)){ // 우선순위가 존재할경우 (뒤로밀림)
                q_priorities.pop(); // 빼주고
                q_priorities.push(pair<int,int>(idx, outNum));  // 뒤로넣고

                priorities.erase(priorities.begin());   // vector 도 빼주고
                priorities.push_back(outNum);   // vector 뒤로 넣고

                idx = -1;
                break;
            }
        }
        if (idx != -1){ // 출력이 가능하다면
            q_priorities.pop(); // 빼주기만
            priorities.erase(priorities.begin());   // vector 도 빼주고
            answer++;
            if (end){
                cout << "answer : " << answer << endl;
                return answer;
            }
        }
        end = 0;
    }

    // cout << q_priorities.front().first << endl;;


    cout << "answer : " << answer << endl;
    return answer;
}

int main(){
    vector<int> priorities;
    int location(2);
    priorities.push_back(2);
    priorities.push_back(1);
    priorities.push_back(3);
    priorities.push_back(2);

    solution(priorities, location);  //1
    priorities.clear();

    location = 0;
    priorities.push_back(1);
    priorities.push_back(1);
    priorities.push_back(9);
    priorities.push_back(1);
    priorities.push_back(1);
    priorities.push_back(1);

    solution(priorities, location);   // 5

}
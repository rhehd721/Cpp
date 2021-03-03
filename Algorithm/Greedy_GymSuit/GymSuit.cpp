// 미완성

// 제한사항
// 전체 학생의 수는 2명 이상 30명 이하입니다.
// 체육복을 도난당한 학생의 수는 1명 이상 n명 이하이고 중복되는 번호는 없습니다.
// 여벌의 체육복을 가져온 학생의 수는 1명 이상 n명 이하이고 중복되는 번호는 없습니다.
// 여벌 체육복이 있는 학생만 다른 학생에게 체육복을 빌려줄 수 있습니다.
// 여벌 체육복을 가져온 학생이 체육복을 도난당했을 수 있습니다. 이때 이 학생은 체육복을 하나만 도난당했다고 가정하며, 
// 남은 체육복이 하나이기에 다른 학생에게는 체육복을 빌려줄 수 없습니다.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    answer = n - lost.size();   // 체육복을 잃어버리지 않은 학생들

    int recv;
    recv = 0;   // lost를 탈출한 명단

    vector<int> lost_copy = lost;

    for (int lo : lost){    // 체육복 여벌이 있으면서 잃어버린 친구들 (즉, 자기 자신에개 주어야되는 사람)
    // cout << "lo : " << lo << endl;
        for (int i =0; i < reserve.size(); i++){    // 여벌있는 명단 돌기
            if (lo == reserve[i]){  // 잃어버린 사람 == 여벌 보유자
                reserve.erase(reserve.begin() + i); // 여벌 보유자 명단에서 삭제
                for (int j =0; j < lost_copy.size(); j++){   // 잃어버린 명단에서 삭제
                    if (lo == lost_copy[j]){
                        lost_copy.erase(lost_copy.begin() + j);
                        break;
                    }
                }
                recv++; // lost 탈출명단 ++
                break;
            }
        }
    }

    if(reserve.size() == 0){return answer + recv;} 

    for (int lo : lost_copy){    // 여벌이 없으면서 잃어버린 친구들
        for (int i =0; i < reserve.size(); i++){    // 빌려줄수 있는 친구 탐색
            if (lo == reserve[i] + 1 || lo == reserve[i] - 1){    // +- 1 의 번호에 친구가 여벌이 있다면 빌려주기
                recv++;
                reserve.erase(reserve.begin() + i); // 빌려줬으니 명단에서 삭제
                break;
            }
        }
    }

    answer += recv;
    cout << answer << endl;
    return answer;
}

int main(){

    int n;
    n = 5;
    vector<int> lost;
    vector<int> reserve;

    lost.push_back(2);
    lost.push_back(4);

    reserve.push_back(1);
    reserve.push_back(3);
    reserve.push_back(5);

    solution(n, lost, reserve); // 5

    lost.clear();
    reserve.clear();

    lost.push_back(2);
    lost.push_back(4);

    reserve.push_back(3);

    solution(n, lost, reserve); // 4

    n = 3;

    lost.clear();
    reserve.clear();

    lost.push_back(3);

    reserve.push_back(1);

    solution(n, lost, reserve); // 2

    n =7;

    lost.clear();
    reserve.clear();

    lost.push_back(1);
    lost.push_back(2);
    lost.push_back(3);
    lost.push_back(4);
    lost.push_back(5);
    lost.push_back(6);
    lost.push_back(7);

    reserve.push_back(1);
    reserve.push_back(2);
    reserve.push_back(3);

    solution(n, lost, reserve); // 3

    return 0;
}
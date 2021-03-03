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
    answer = n - lost.size();   // 체육복을 잊어버리지 않은 학생들

    int recv;
    recv = 0;   // 체육복을 다른 친구에게 받은 학생

    for (int lo : lost){    // 체육복 여벌이 있으면서 잃어버린 친구들 구하기
        for (int i =0; i < reserve.size(); i++){
            if (lo == reserve[i]){
                for (int j =0; j < reserve.size(); j++){ // 여벌 보유자 명단에서 삭제
                    if (reserve[i] == reserve[j]){
                        reserve.erase(reserve.begin() + j);
                    }
                }
                for (int j =0; j < lost.size(); j++){   // 잃어버린 명단에서 삭제
                    if (lo == lost[j]){
                        lost.erase(lost.begin() + j);
                    }
                }
                recv++; // 체육복 생긴사람 ++
                i--;
            }
        }
    }

    for (int lo : lost){    // 여벌이 없으면서 잃어버린 친구들
        for (int i =0; i < reserve.size(); i++){
            if (lo == reserve[i] + 1 || reserve[i] - 1){    // +- 1 의 번호에 친구가 여벌이 있다면 빌려주기
                recv++;
                reserve.erase(reserve.begin() + i);
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

    return 0;
}
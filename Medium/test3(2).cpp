#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<long long> solution(long long n){
    vector<long long> answer;
    vector<int> list;
    int list_idx(0);
    int check(0);


    // 모든 약수 구하기
    for (int i = 1; i <= n; i++){
        if(i == 1){continue;}

        if((n%i) ==0){  // 약수인가
            check = 0;
            for(int j = 2; j < i; j++){ // 소수인가
                if((i%j) == 0){
                    check++;
                    break;
                }
            }
            if(check){}
            else{
                list.push_back(i);  // 소수만 추가
            }
        }
    }

    int tem(0);
    for(int i = 0; i < list.size(); i++){   // 소수들이 들은 vector 탐색
        tem = (n / list[i]);    // 짝궁
        for(int j = i; j < list.size(); j++){
            if(j == i){continue;}
            if(tem == list[j]){ // 짝궁을 찾았다면
                answer.push_back(list[i]);
                answer.push_back(tem);
                // break;  
            }
        }
    }

    if(!answer.size()){
        answer.push_back(-1);
        answer.push_back(-1);
    }

    cout << "answer  : ";
    for (long long i : answer){
        cout << i << ", ";
    }
    cout << endl;
    return answer;
}

int main(){
    solution(6);    // 2,3
    solution(12);   // -1, -1
    solution(2);   // -1, -1
}

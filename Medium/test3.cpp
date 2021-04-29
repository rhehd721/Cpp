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
    int tem(0);
    int check2(0);

    // 모든 약수 구하기
    for (int i = 1; i <= n; i++){
        if(i == 1){continue;}
        if((n%i) ==0){  // 약수인가
            check = 0;
            check2 = 0;
            for(int j = 2; j < i; j++){ // 소수인가
                if((i%j) == 0){
                    check++;
                    break;
                }
            }
            if(check){}
            else{
                tem = (n / i);
                for(int k = 2; k < tem; k++){
                    if((tem%k) == 0){
                    check2++;
                    break;
                }
                if(check2){}
                else{
                    answer.push_back(i);
                    answer.push_back(tem);
                    return answer;
                }
                }
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

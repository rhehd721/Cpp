// 제한사항
// numbers는 길이 1 이상 7 이하인 문자열입니다.
// numbers는 0~9까지 숫자만으로 이루어져 있습니다.
// "013"은 0, 1, 3 숫자가 적힌 종이 조각이 흩어져있다는 의미입니다.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string numbers) {
    int answer = 0;
    vector<int> vec_num;
    vector<int> make_nums;
    string maxNum;
    int cnt(0);

    bool check;

    for (char i : numbers){ // 문자열로 된 숫자를 하나씩 때어낸다
        vec_num.push_back(int(i - 48));
    }
    sort(vec_num.begin(), vec_num.end(), greater<int>());

    for (int i : vec_num){  // 숫자들로 만들 수 있는 가장 큰 숫자
        maxNum += to_string(i);
    }

    for (int i = 0; i <= stoi(maxNum); i++){
        for(int j = 0; j < 10; j++){
            cnt = 0;
            for (char k : to_string(i)){
                if(j == int(k-48)){
                    cnt++;
                }
            }
            if (cnt > count(vec_num.begin(), vec_num.end(), j)){   // 갯수가 다르면
                check = false;
                break;
            }
            else{
                check = true;
            }
        }
        if(!check){  // i 가 vec_num에 들어있는 숫자로만 구성되었다면
            check = true;
        }
        else{
            cout << i << ", ";
            make_nums.push_back(i);
            check = true;
        }
    }

    for (int i : make_nums){    // 만든 숫자 소수인지 확인하기
        for (int check = 2; check <= i; check++){
            if(check == i){
                answer++;
            }
            else{
                if((i % check) == 0){
                    break;
                }
            }
        }
    }

    cout << "\n answer : " << answer << endl << endl;
    return answer;
}

int main(){
    string numbers("17");
    solution(numbers);   // 3
    numbers = "011";
    solution(numbers);   // 2
}


    // for (int i : vec_num){
    //     cout << i << ", ";
    // }
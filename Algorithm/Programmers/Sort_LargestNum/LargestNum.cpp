// 제한 사항
// numbers의 길이는 1 이상 100,000 이하입니다.
// numbers의 원소는 0 이상 1,000 이하입니다.
// 정답이 너무 클 수 있으니 문자열로 바꾸어 return 합니다
// 0, 1~9, 10~99. 100~999, 1000

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// string solution(vector<int> numbers) {
//     string answer = "";
//     vector<int> num;
//     string result = "";

//     // 들어온 숫자 1자리씩 잘라 새로운 숫자 arr 만들기
//     cout << "\n Numbers : ";
//     for (int i : numbers){ 
//         answer += to_string(i);
//         cout << i << ", ";
//     }
//     for (char i : answer){
//         num.push_back(int(i) - 48);
//     }

//     // 새로운 숫자 arr를 내림차순 정렬
//     cout << "\n num before sort: ";
//     for (int i : num){
//         cout << i << ", ";
//     }
//     sort(num.begin(), num.end(), greater<int>());
//     cout << "\n num after sort: ";
//     for (int i : num){
//         result += to_string(i);
//         cout << i << ", ";
//     }


//     cout << "\n answer : " <<  answer << endl;
//     cout << "\n result : " <<  result << endl;
//     // int answer2 = stoi(answer);
//     // cout << "answer2 : " << answer2 << endl;
//     return answer;
// }


string solution(vector<int> numbers) {
    string answer = "";

    vector<int> zeros;
    vector<int> ones;
    vector<int> TensDigit;
    vector<int> Hundred;
    vector<int> thousand;

    sort(numbers.begin(), numbers.end(), greater<int>());
    // 자릿수별로 숫자 나누기
    for (int i : numbers){
        if (i == 0){ // 0
            zeros.push_back(i);
        }
        else if (i < 10 && i > 0){ // 1 ~ 9
            ones.push_back(i);
        }
        else if (i < 100 && i >= 10){ // 10 ~ 99
            TensDigit.push_back(i);
        }
        else if (i < 10 && i > 0){ // 100 ~ 999
            Hundred.push_back(i);
        }
        else{ // 1000
            thousand.push_back(i);
        }
    }

    // cout << "\n zeros : ";
    // for (int i : zeros){
    //     cout << i << ", ";
    // }
    // cout << "\n ones : ";
    // for (int i : ones){
    //     cout << i << ", ";ㅌ 
    // }
    // cout << "\n TensDigit : ";
    // for (int i : TensDigit){
    //     cout << i << ", ";
    // }
    // cout << "\n Hundred : ";
    // for (int i : Hundred){
    //     cout << i << ", ";
    // }
    // cout << "\n thousand : ";
    // for (int i : thousand){
    //     cout << i << ", ";
    // }

    
    
    
    

    cout << "answer : " << answer << endl << endl; 
    return answer;
}


int main(){
    cout << "1 번 문제 \n";
    vector<int> numbers;
    numbers.push_back(6);
    numbers.push_back(10);
    numbers.push_back(2);
    solution(numbers);  //	6210

    cout << "2 번 문제 \n";
    numbers.clear();
    numbers.push_back(3);
    numbers.push_back(30);
    numbers.push_back(34);
    numbers.push_back(5);
    numbers.push_back(9);
    solution(numbers);  //	9534330

}
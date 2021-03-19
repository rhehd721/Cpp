// 제한 사항
// numbers의 길이는 1 이상 100,000 이하입니다.
// numbers의 원소는 0 이상 1,000 이하입니다.
// 정답이 너무 클 수 있으니 문자열로 바꾸어 return 합니다

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    vector<int> num;
    string result = "";

    // 들어온 숫자 1자리씩 잘라 새로운 숫자 arr 만들기
    cout << "\n Numbers : ";
    for (int i : numbers){ 
        answer += to_string(i);
        cout << i << ", ";
    }
    for (char i : answer){
        num.push_back(int(i) - 48);
    }

    // 새로운 숫자 arr를 내림차순 정렬
    cout << "\n num before sort: ";
    for (int i : num){
        cout << i << ", ";
    }
    sort(num.begin(), num.end(), greater<int>());
    cout << "\n num after sort: ";
    for (int i : num){
        result += to_string(i);
        cout << i << ", ";
    }





    cout << "\n answer : " <<  answer << endl;
    cout << "\n result : " <<  result << endl;
    // int answer2 = stoi(answer);
    // cout << "answer2 : " << answer2 << endl;
    return answer;
}

int main(){
    vector<int> numbers;
    numbers.push_back(6);
    numbers.push_back(10);
    numbers.push_back(2);
    solution(numbers);  //	6210

    numbers.clear();
    numbers.push_back(3);
    numbers.push_back(30);
    numbers.push_back(34);
    numbers.push_back(5);
    numbers.push_back(9);
    solution(numbers);  //	9534330

}
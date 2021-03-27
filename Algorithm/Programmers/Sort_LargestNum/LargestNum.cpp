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

string solution(vector<int> numbers) {
    string answer = "";

    sort(numbers.begin(), numbers.end(), greater<int>());

    for (int i : numbers){
        cout << i << ", ";
    }






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
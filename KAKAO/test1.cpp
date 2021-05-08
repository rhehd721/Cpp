// 제한사항
// 1 ≤ s의 길이 ≤ 50
// s가 "zero" 또는 "0"으로 시작하는 경우는 주어지지 않습니다.
// return 값이 1 이상 2,000,000,000 이하의 정수가 되는 올바른 입력만 s로 주어집니다.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

int solution(string s) {
    int answer = 0;
    string result;
    string spelling = "";

    for(int i(0); i < s.size(); i++){
        // 숫자
        if(s[i] < 58){
            result += s[i];
        }
        // 문자 시작
        else{
            spelling += s[i];
            if(spelling == "zero"){
                result += "0";
                spelling = "";
            }
            else if(spelling == "one"){
                result += "1";
                spelling = "";
            }
            else if(spelling == "two"){
                result += "2";
                spelling = "";
            }
            else if(spelling == "three"){
                result += "3";
                spelling = "";
            }
            else if(spelling == "four"){
                result += "4";
                spelling = "";
            }
            else if(spelling == "five"){
                result += "5";
                spelling = "";
            }
            else if(spelling == "six"){
                result += "6";
                spelling = "";
            }
            else if(spelling == "seven"){
                result += "7";
                spelling = "";
            }
            else if(spelling == "eight"){
                result += "8";
                spelling = "";
            }
            else if(spelling == "nine"){
                result += "9";
                spelling = "";
            }
        }
    }

    stringstream ssInt(result);
    ssInt >> answer;


    cout << "answer : " << answer << endl;
    return answer;
}

int main(){
    string s = "one4seveneight";
    solution(s); //	1478
    s = "23four5six7";
    solution(s); //	234567
    s = "2three45sixseven";
    solution(s); //	234567
    s = "123";
    solution(s); //	123
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

vector<int> solution(string code, string day, vector<string> data) {
    vector<int> answer;

    vector<pair<int, int> > tem; // 해당 날짜와 코드가 맞는 문자열을 담을 vector

    for(string i : data){   // 문자열 덩어리 순회
        int cnt(0);
        string Check_code = "";
        string Check_day = "";
        string time = "";
        string price = "";
        for(int j(0); j < i.size(); j++){   // 문자열 한글자씩 순회
            if(i[j] == '='){
                cnt++;
                if(cnt == 2){   // code 시작
                    for(int k(j+1); k < j+7; k++){
                        Check_code += i[k];
                    }
                    if(Check_code == code){ // 일단 code 는 같은경우
                        j+=5;
                    }
                    else{   // code가 같지 않다면 패스
                        break;
                    }
                }
                else if(cnt == 3){   // time 시작
                    for(int k(j+1); k < j+9; k++){
                        Check_day += i[k];
                    }
                    if(Check_code == code){ // 일단 code 는 같은경우
                        int tem1(0);
                        int tem2(0);
                        time = (i[j+9] + i[j+10]);
                        string pa = "";
                        for(int idx(6); pa != " "; idx++){
                            pa = i[idx];
                            price += pa;
                        }
                        stringstream ssInt1(time);
                        ssInt1 >> tem1;
	                    stringstream ssInt2(price);
                        ssInt1 >> tem2;
                        tem.push_back(pair<int, int>(tem1,tem2));
                    }
                    break;
                }
            }
        }
    }
    sort(tem.begin(), tem.end());
    for(auto i : tem){
        answer.push_back(i.second);
    }

    return answer;
}


int main(){

    cout << "answer : " << endl;

}
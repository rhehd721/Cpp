// 제한사항
// s의 길이는 1 이상 1,000 이하입니다.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = 0;

    if((s.size() % 2)){
        cout << 0 << endl;
        return 0;
    }

    int cycle(s.size() - 1);
    if(cycle <= 0){
        cycle = 0;
    }
    char A = '[';
    char a = ']';

    char B = '(';
    char b = ')';

    char C = '{';
    char c = '}';

    int idx(cycle);

    for (int i(0); i <= cycle; i++){
        int h(cycle - i);
        int check(0);
        int check_A(0);
        int check_B(0);
        int check_C(0);
        
        for(int k(0); k < s.size(); k++){
            if(h < 0){
                h = cycle;
            }
            
            if(s[h] == a){
                check_A++;
            }
            else if(s[h] == b){
                check_B++;
            }
            else if(s[h] == c){
                check_C++;
            }
            else if(s[h] == A){
                check_A--;
            }
            else if(s[h] == B){
                check_B--;
            }
            else if(s[h] == C){
                check_C--;
            }

            if(check_A < 0 || check_B < 0 || check_C < 0){
                check = 1;
                break;
            }
            // cout << h << endl;
            h--;
        }
        if(!check){
            answer++;
        }
    }

    cout << answer << endl;
    return answer;
}

int main(){
    string s;
    s = "[](){}";
    cout << "########################" << endl;
    solution(s); // 3

    cout << "########################" << endl;
    s = "}]()[{";
    solution(s); // 2

    cout << "########################" << endl;
    s = "[)(]";
    solution(s); // 0

    cout << "########################" << endl;
    s = "}}}";
    solution(s); // 0

    cout << "########################" << endl;
    s = "}";
    solution(s); // 0

}
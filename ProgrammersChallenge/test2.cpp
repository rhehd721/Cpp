// 제한사항
// s의 길이는 1 이상 1,000 이하입니다.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = -1;

    if(!(s.size() % 2)){
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

    int check_A(0);
    int check_B(0);
    int check_C(0);

    int idx(cycle);

    for (int i(0); i <= cycle; i++){
        int h(cycle - i);
        cout << "cycle" << endl;
        for(int k(0); k < s.size(); k++){
            if(h < 0){
                h = cycle;
            }
            cout << h << endl;
            h--;
        }
    }

    // cout << answer << endl;
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
// ▲ - 다음 알파벳
// ▼ - 이전 알파벳 (A에서 아래쪽으로 이동하면 Z로)
// ◀ - 커서를 왼쪽으로 이동 (첫 번째 위치에서 왼쪽으로 이동하면 마지막 문자에 커서)
// ▶ - 커서를 오른쪽으로 이동

// 제한 사항
// name은 알파벳 대문자로만 이루어져 있습니다.
// name의 길이는 1 이상 20 이하입니다.

// A 65 Z 90

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string make_Start(string name){
    string Start;
    for (int i(0); i < name.size(); i++){
        Start += 'A';
    }

    return Start;
}

vector<int> make_Not_A(string name){
    vector<int> Not_A;

    // 글자에서 A가 아닌 index를 찾는다
    int index(0);
    for (char i : name){
        if(i != 'A'){
        Not_A.push_back(index);
    }
    index++;
    }

    return Not_A;
}

int solution(string name) {
    int answer = 1;

    for (char i : name){
        if(i != 'A'){
            answer = 0;
        }
    }

    if(!answer){
        answer = 0;
    }
    else{
        cout << "answer : " << 0 << endl;
        return 0;
    }

    string Start_A = make_Start(name);
    vector<int> Not_A_IdxList = make_Not_A(name);

    int current(0); // 현재 나의 위치
    int front(0);
    int tail(Not_A_IdxList.size() - 1);

    while(front != tail){
        int go = Not_A_IdxList[front] - current;
        int back = (name.size() - Not_A_IdxList[tail]) + current;
        cout << "go : " << go << " back :" << back << endl;

        if(go <= back){ // 앞으로 전진
            if(int(name[Not_A_IdxList[front]]) <= 77){
                answer += int(name[Not_A_IdxList[front]]) - int('A') + go;
            }
            else{
                answer += 91 - int(name[Not_A_IdxList[front]]) + go;
            }
            cout << "in_go : " << name[Not_A_IdxList[front]] << endl;
            current = Not_A_IdxList[front];
            front++;
        }
        else{ // 뒤로 돌아가기
            if(int(name[Not_A_IdxList[tail]]) <= 77){
                answer += int(name[Not_A_IdxList[tail]]) - int('A') + back;
            }
            else{
                answer += 91 - int(name[Not_A_IdxList[tail]]) + back;
            }
            cout << "in_back : " << name[Not_A_IdxList[tail]] << endl;
            current = Not_A_IdxList[tail];
            tail--;
        }
        cout << "front : " << front << endl;
        cout << "tail : " << tail << endl;
        cout << "current : " << current << endl << endl;
    }

    int go = Not_A_IdxList[front] - current;
    int back = (name.size() - Not_A_IdxList[tail]) + current;

    if(go <= back){
        if(int(name[Not_A_IdxList[front]]) <= 77){
            answer += int(name[Not_A_IdxList[front]]) - int('A') + go;
        }
        else{
            answer += 91 - int(name[Not_A_IdxList[front]]) + go;
        }
    }
    else{
        if(int(name[Not_A_IdxList[front]]) <= 77){
            answer += int(name[Not_A_IdxList[front]]) - int('A') + back;
        }
        else{
            answer += 91 - int(name[Not_A_IdxList[front]]) + back;
        }
    }

    cout << endl << "answer : " << answer << endl << endl;
    return answer;
}

int main(){
    string name;
    name = "JEROEN";
    cout << "################## solution 1" << endl<< endl;
    solution(name); // 56

    name = "JAN";
    cout<< endl << "############### solution 2" << endl<< endl;
    solution(name); // 23

    name = "BA";
    cout<< endl << "############### solution 3" << endl<< endl;
    solution(name); // 1

    name = "AAB";
    cout<< endl << "############### solution 4" << endl<< endl;
    solution(name); // 2

    name = "CAAAACCAAAACC";
    cout<< endl << "############### solution 5" << endl<< endl;
    solution(name); // 2

    return 0;
}
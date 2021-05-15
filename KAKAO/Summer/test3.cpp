#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// "U X": 현재 선택된 행에서 X칸 위에 있는 행을 선택합니다.
// "D X": 현재 선택된 행에서 X칸 아래에 있는 행을 선택합니다.
// "C" : 현재 선택된 행을 삭제한 후, 바로 아래 행을 선택합니다. 단, 삭제된 행이 가장 마지막 행인 경우 바로 윗 행을 선택합니다.
// "Z" : 가장 최근에 삭제된 행을 원래대로 복구합니다. 단, 현재 선택된 행은 바뀌지 않습니다.

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    int Currently_idx(k);   // 현재 내 위치
    vector<int> last_del;   // 마지막으로 지운 자리

    // 초기화
    char Currently_result[n];
    for(int i(0); i < n; i++){
        Currently_result[i] = 'O';
    }

    // cmd 작업
    for(string Command : cmd){
        // cout << "Currently_idx : " << Currently_idx << endl;
        if(Command[0] == 'U'){  // Command[2]; // 이만큼 위로
            for(int i(0); i < (Command[2] - 48); i++){ // 0 idx라면
                if(!Currently_idx){
                    Currently_idx = n;
                }

                Currently_idx--;

                if(Currently_result[Currently_idx] == 'X'){ // X 자리는 없는 자리로 취급
                    i--; 
                }
            }
        }
        else if(Command[0] == 'D'){ // Command[2]; // 이만큼 아래로
            for(int i(0); i < (Command[2] - 48); i++){
                if(Currently_idx == (n-1)){ // 마지막 idx라면 
                    Currently_idx = -1;
                }

                Currently_idx++;

                if(Currently_result[Currently_idx] == 'X'){ // X 자리는 없는 자리로 취급
                    i--; 
                }
            }
        }
        else if(Command[0] == 'C'){ // 삭제 후 아래로 한칸
            Currently_result[Currently_idx] = 'X';
            last_del.push_back(Currently_idx);

            if(Currently_idx == (n-1)){ // 마지막 idx라면 
                while(1){
                    Currently_idx--;
                    if(Currently_result[Currently_idx] == 'O'){ // X 자리는 없는 자리로 취급
                        break;
                    }
                    if(!Currently_idx){
                        Currently_idx = n;
                    }
                }
            }
            else{
                while(1){
                    Currently_idx++;
                    if(Currently_result[Currently_idx] == 'O'){ // X 자리는 없는 자리로 취급
                        break;
                    }
                    if(Currently_idx == (n-1)){ // 마지막 idx라면 
                        Currently_idx = -1;
                    }
                }
            }
        }
        else if(Command[0] == 'Z'){   // Z 되돌리기
            Currently_result[last_del.back()] = 'O';
            last_del.pop_back();
        }

    }


    for(int i(0); i < n; i++){
        answer += Currently_result[i];
    }
    cout << "answer : " << answer << endl;
    return answer;
}

int main(){
    int n(8);
    int k(2);
    vector<string> cmd;
    cmd.push_back("D 2");//
    cmd.push_back("C");//
    cmd.push_back("U 3");//
    cmd.push_back("C");//
    cmd.push_back("D 4");//
    cmd.push_back("C");//
    cmd.push_back("U 2");//
    cmd.push_back("Z");
    cmd.push_back("Z");
    solution(n, k, cmd);    // "OOOOXOOO"

    cmd.clear();
    cmd.push_back("D 2");
    cmd.push_back("C");
    cmd.push_back("U 3");
    cmd.push_back("C");
    cmd.push_back("D 4");
    cmd.push_back("C");
    cmd.push_back("U 2");
    cmd.push_back("Z");
    cmd.push_back("Z");
    cmd.push_back("U 1");
    cmd.push_back("C");
    solution(n, k, cmd);    // "OOXOXOOO"
    
}
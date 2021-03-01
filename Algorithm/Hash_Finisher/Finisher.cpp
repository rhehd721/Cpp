// 제한사항
// 마라톤 경기에 참여한 선수의 수는 1명 이상 100,000명 이하입니다.
// completion의 길이는 participant의 길이보다 1 작습니다.
// 참가자의 이름은 1개 이상 20개 이하의 알파벳 소문자로 이루어져 있습니다.
// 참가자 중에는 동명이인이 있을 수 있습니다.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = ""; // 초기화
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    int a = 0;

    if (participant.size() == 1){
        return answer = participant.at(0);
    }

    for (int i = 0; i < completion.size(); i++){
        if (participant.at(i) != completion.at(i)){
            a = 1;
        }
        if(a == 1){
            answer = participant.at(i);
            break;
        }
        if(i == completion.size() - 1){
            if(a != 1){
                answer = participant.at(participant.size()-1);
            }
        }
    }
    return answer;
}

int main(){
    vector<string> participant;
    participant.push_back("leo");
    participant.push_back("kiki");
    participant.push_back("eden");
    vector<string>  completion;
    completion.push_back("eden");
    completion.push_back("kiki");


    // cout << participant[0] << ':' << participant[1] << ':'<< participant[2] << endl;

    // participant.clear();

    // cout << participant.size() << endl;


    // solution(participant, completion);
    // // return = "leo"
    // participant.clear();
    // completion.clear();

    // participant = ["marina", "josipa", "nikola", "vinko", "filipa"]
    // completion = ["josipa", "filipa", "marina", "nikola"]
    // solution(vector<string> participant, vector<string> completion)
    // participant.clear();
    // completion.clear();
    // // return = "vinko"

    // participant = ["mislav", "stanko", "mislav", "ana"]
    // completion = ["stanko", "ana", "mislav"]
    // solution(vector<string> participant, vector<string> completion)
    // // return = "mislav"

    return 0;
}
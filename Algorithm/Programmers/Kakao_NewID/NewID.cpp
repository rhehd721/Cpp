// 아이디의 길이는 3자 이상 15자 이하여야 합니다.
// 아이디는 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.) 문자만 사용할 수 있습니다.
// 단, 마침표(.)는 처음과 끝에 사용할 수 없으며 또한 연속으로 사용할 수 없습니다.

// step 
// 1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
// 2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
// 3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
// 4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
// 5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
// 6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
//      만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
// 7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.

// [제한사항]
// new_id는 길이 1 이상 1,000 이하인 문자열입니다.
// new_id는 알파벳 대문자, 알파벳 소문자, 숫자, 특수문자로 구성되어 있습니다.
// new_id에 나타날 수 있는 특수문자는 -_.~!@#$%^&*()=+[{]}:?,<>/ 로 한정됩니다.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";

    // cout << "처음 : " << new_id << endl;

    for (int i(0); i < new_id.size(); i++){
        // 1단계 대문자 -> 소문자
        if(new_id[i] >= 65  && new_id[i] <= 90){
            new_id[i] = char(int(new_id[i]) + 32);
        }
    }
    // cout << endl << "대문자 제거 : " << new_id << endl;

    // 2단계 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.) 이 아니라면 제거
    // 97 ~ 122 = 소문자
    // 48 ~ 57 = 숫자
    // 45,46 = - .
    // 95 = _
    for (int i(0); i < new_id.size(); i++){
        if(!((new_id[i] >= 48  && new_id[i] <= 57) || new_id[i] == 45 || new_id[i] == 46 || new_id[i] == 95 || (97 <= new_id[i] && new_id[i] <= 122))){
            new_id.erase(new_id.begin() + i);
            i--;
        }
    }
    // cout << endl << "필요없는 문자 제거 : " << new_id << endl;

    int start(0);
    int cnt(0);
    for (int i(0); i < new_id.size(); i++){
        if(new_id[i] == 46){    // 마침표 발견
            if(!cnt){   // .이 시작되는 지점 저장
                start = i;
            }
            cnt++;  // 마침표 갯수 증가
        }
        else{
            if(!cnt){  // cnt = 0 이면 아무런 동작 없음 
                continue;
            }
            else{   // cnt가 존재한다면 작업
                // cout << endl << "before : " << new_id << endl;
                new_id.erase(new_id.begin() + start, new_id.begin() + start + cnt - 1);
                // cout << endl << "after : " << new_id << endl;
                start = 0;
                i -= cnt;
                cnt = 0;
            }
        }
    }
    // cout << endl << "마침표 줄이기 : " << new_id << endl;

    // 4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
    while(1){
        if(new_id[0] == 46){
            new_id.erase(new_id.begin());
        }
        else{
            break;
        }
    }
    while(1){
        if(new_id[new_id.size() - 1] == 46){
            new_id.erase(new_id.begin() + new_id.size() - 1);
        }
        else{
            break;
        }
    }
    // cout << endl << "맨처음 또는 마지막 마침표 재거 : " << new_id << endl;

    // 5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
    if(new_id.size() == 0){
        answer = "aaa";
        // cout << endl << "빈문자라면 : " << new_id << endl;
        return answer;
    }

    // 6단계 사이즈 줄이기
    if(new_id.size() >= 16){
        new_id.erase(new_id.begin() + 15, new_id.end());
    }
    // cout << endl << "15글자 이내 : " << new_id << endl;
    while(1){
        if(new_id[new_id.size() - 1] == 46){
            new_id.erase(new_id.begin() + new_id.size() - 1);
        }
        else{
            break;
        }
    }

    // 7단계
    char x;
    if(new_id.size() <= 2){
        x = new_id[new_id.size() - 1];
        for(int i = new_id.size(); i < 3; i++){
            new_id += x;
        }
    }


    answer = new_id;

    cout << answer << endl << endl;
    return answer;
}
int main(){
    string new_id = "...!@BaT#*..y.abcdefghijklm.";
    // solution(new_id); //	"bat.y.abcdefghi"
    new_id = "z-+.^.";
    solution(new_id); // "z--"
    // new_id = "=.=";
    // solution(new_id); // "aaa"
    // new_id = "123_.def";
    // solution(new_id); // "123_.def"
    // new_id = "abcdefghijklmn.p";
    // solution(new_id); // "abcdefghijklmn"
}
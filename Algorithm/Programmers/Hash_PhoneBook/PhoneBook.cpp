// 제한 사항
// phone_book의 길이는 1 이상 1,000,000 이하입니다.
// 각 전화번호의 길이는 1 이상 20 이하입니다.

#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    int check = 0;
    int index = 0;

    for (string PhoneNum : phone_book){
        for (int i=0; i < phone_book.size(); i++){  // 전체 arr 분석
            if(i == check){ // 자기 자신과는 비교하지 않는다.
                continue;
            }
            for (int j =0; j < PhoneNum.size(); j++){   // 글자의 크기만큼 비교
                if(PhoneNum[j] == phone_book[i][j]){
                    index++;
                }
            }
            if (index == PhoneNum.size()){
                return false;
            }
            else{
                index = 0;
            }
        }
        check++;
    }

    cout << answer << endl;

    return answer;
}

int main(){
    vector<string> phone_book;
    phone_book.push_back("119");
    phone_book.push_back("97674223");
    phone_book.push_back("1195524421");

    solution(phone_book);

    phone_book.clear();

    phone_book.push_back("123");
    phone_book.push_back("456");
    phone_book.push_back("789");

    solution(phone_book);
}
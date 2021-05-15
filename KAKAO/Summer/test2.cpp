// places의 행 길이(대기실 개수) = 5
// places의 각 행은 하나의 대기실 구조를 나타냅니다.
// places의 열 길이(대기실 세로 길이) = 5
// places의 원소는 P,O,X로 이루어진 문자열입니다.
// places 원소의 길이(대기실 가로 길이) = 5
// P는 응시자가 앉아있는 자리를 의미합니다.
// O는 빈 테이블을 의미합니다.
// X는 파티션을 의미합니다.
// 입력으로 주어지는 5개 대기실의 크기는 모두 5x5 입니다.
// return 값 형식
// 1차원 정수 배열에 5개의 원소를 담아서 return 합니다.
// places에 담겨 있는 5개 대기실의 순서대로, 거리두기 준수 여부를 차례대로 배열에 담습니다.
// 각 대기실 별로 모든 응시자가 거리두기를 지키고 있으면 1을, 한 명이라도 지키지 않고 있으면 0을 담습니다.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// P는 응시자가 앉아있는 자리를 의미합니다.
// O는 빈 테이블을 의미합니다.
// X는 파티션을 의미합니다.

 

vector<int> solution(vector<vector<string> > places) {
    vector<int> answer;
    bool Check_end(0);

    vector<pair<int, int> > Person;
    vector<pair<int, int> > partition;

    // 맨해튼 거리는 |r1 - r2| + |c1 - c2|
    int Manhattan(0);

    // 5 * 5 파티션
    string arr[5][5];

    // arr에 채워주기
    
    for(vector<string> pla : places){
        int idx_1(0);
        // 각 경우 넣어주기
        for(string pl : pla){
            int idx_2(0);
            for(char p : pl){
                arr[idx_1][idx_2++] = p;
            }
            idx_1++;
        }

        // P와 X의 위치 넣어주기
        for(int i(0); i < 5; i++){
            for(int j(0); j < 5; j++){
                if(arr[i][j] == "P"){Person.push_back(pair<int, int>(i, j));}
                else if(arr[i][j] == "X"){partition.push_back(pair<int, int>(i, j));}
            }
        }
        cout << "P : " << Person.size() << endl;
        // cout << "X : " << partition.size() << endl;

        // 맨허튼 유지여부
        
        for(int i(0); i < Person.size(); i++){
            Manhattan = 0;
            for(int j(i); j < Person.size(); j++){
                if(j == i){continue;}
                // 맨해튼 거리는 |r1 - r2| + |c1 - c2|
                if((Person[i].first - Person[j].first) < 0){
                    Manhattan += (-(Person[i].first - Person[j].first));
                }
                else{
                    Manhattan += (Person[i].first - Person[j].first);
                }

                if((Person[i].second - Person[j].second) < 0){
                    Manhattan += (-(Person[i].second - Person[j].second));
                }
                else{
                    Manhattan += (Person[i].second - Person[j].second);
                }
                cout << "Manhattan : " << Manhattan << endl;
                if(Manhattan <= 2){ // 거리두기가 안되었다면 0
                    answer.push_back(0);
                    Check_end = 1;
                    break;
                }
            }

            if(Check_end){
                break;
            }
        }
        if(!Check_end){answer.push_back(1);}
        else{Check_end = 0;}
        // 새로운 Person 입력을 위한 초기화 
        Person.clear();



        // for(int i(0); i < 5; i++){
        //     for(int j(0); j < 5; j++){
        //         cout << arr[i][j] << ", ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
    }

    cout << "answer : ";
    for(int i : answer){
        cout << i << ", ";
    }
    cout << endl;
    return answer;
}

int main(){

    vector<vector<string> > places;
    vector<string> tem;
    tem.push_back("POOOP");
    tem.push_back("OXXOX");
    tem.push_back("OPXPX");
    tem.push_back("OOXOX");
    tem.push_back("POXXP");
    places.push_back(tem);

    tem.clear();
    tem.push_back("POOPX");
    tem.push_back("OXPXP");
    tem.push_back("PXXXO");
    tem.push_back("OXXXO");
    tem.push_back("OOOPP");
    places.push_back(tem);

    tem.clear();
    tem.push_back("PXOPX");
    tem.push_back("OXOXP");
    tem.push_back("OXPXX");
    tem.push_back("OXXXP");
    tem.push_back("POOXX");
    places.push_back(tem);

    tem.clear();
    tem.push_back("OOOXX");
    tem.push_back("XOOOX");
    tem.push_back("OOOXX");
    tem.push_back("OXOOX");
    tem.push_back("OOOOO");
    places.push_back(tem);

    tem.clear();
    tem.push_back("PXPXP");
    tem.push_back("XPXPX");
    tem.push_back("PXPXP");
    tem.push_back("XPXPX");
    tem.push_back("PXPXP");
    places.push_back(tem);
    solution(places); // 1, 0, 1, 1, 1

}
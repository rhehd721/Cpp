// 제한사항
// 컴퓨터의 개수 n은 1 이상 200 이하인 자연수입니다.
// 각 컴퓨터는 0부터 n-1인 정수로 표현합니다.
// i번 컴퓨터와 j번 컴퓨터가 연결되어 있으면 computers[i][j]를 1로 표현합니다.
// computer[i][i]는 항상 1입니다.

// 네트워크의 수를 구하여라
// 1. 모두 연결되어있지 않은경우    자기 자신만 1
// 2. 모두 연결되어있는 경우    
// 3. 부분만 연결된 경우

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int> > computers) {
    int answer = 0;

    




    // for (int computersIdx = 0; computersIdx < computers.size(); computersIdx++){
    //     for (vector<int> com : computers){
    //         for (int j = 0; j < n; j++){
    //             if (computersIdx == j){
    //                 continue;
    //             }
    //             else{
    //                 if (){
    //                     return 1;
    //                 }
    //                 else if(){
    //                     return 0;
    //                 }

    //             }
    //         }
    //     }
    // }


    cout << answer << endl;
    return answer;
}

int main(){
    int n;

    n =3;
    
    vector<vector<int> > computers;

    vector<int> middle;

    middle.push_back(1);
    middle.push_back(1);
    middle.push_back(0);

    computers.push_back(middle);
    computers.push_back(middle);

    middle.clear();

    middle.push_back(0);
    middle.push_back(0);
    middle.push_back(1);

    computers.push_back(middle);

    solution(n, computers);
    
    // return 2

    middle.push_back(1);
    middle.push_back(1);
    middle.push_back(0);

    computers.push_back(middle);

    middle.clear();

    middle.push_back(1);
    middle.push_back(1);
    middle.push_back(1);

    computers.push_back(middle);

    middle.clear();

    middle.push_back(0);
    middle.push_back(1);
    middle.push_back(1);

    computers.push_back(middle);

    solution(n, computers);

    // return 1
}
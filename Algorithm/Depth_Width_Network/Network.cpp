// 미완성

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
    int check = 0;

    const int computerNum = n;

    vector<int> Total;
    Total.resize(n);

    for (int i = 0; i < n; i++){
        for (vector<int> com : computers){
            Total[i] += com[i];
        }
    }

    vector<int> result;
    result.resize(n);
    
    for (int i =0; i < n; i++){
        for (int j =0; j < n; j++){
            if( i+1 == Total[j]){
                result[i]++;
            }
        }
    }

    answer += result[0];
    for (int i =0; i < n; i++){
        if (i == 0){
            continue;
        }
        else{
            if(result[i] >= 2){
                answer++;
            }
        }
    }

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

    cout << "1번 문제" << endl;

    solution(n, computers);
    
    // return 2

    computers.clear();

    middle.clear();

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

    cout << "2번 문제" << endl;

    solution(n, computers);

    // return 1
}
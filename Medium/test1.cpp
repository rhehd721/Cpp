#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<int> solution(vector<vector< int> > paths){
    vector< int > answer;
    int start(-1);
    int end(-1);
    int check(0);

    sort(paths.begin(),paths.end());

    for (int i = 0; i < paths.size(); i++){
        cout << "i : "<< i << endl;
        check = 0;
        if(paths[i][0] > paths[i][1]){  // 큰수에서 작은수로
            start = paths[i][1];    // 시작점 넣어주기
            end = paths[i][0];   // 현재 끝점 넣어주기

            for(int j = i; j < paths.size(); j++){    // 7,6  8,7
            if(end == paths[j][1]){ // 길이 이어져 있다면 연장하기
                end = paths[j][0];
            }
            else{   // 길이 끝났다면 answer 추가
                if(j == i){continue;}
                answer.push_back(end);
                answer.push_back(start);
                i = j - 1;  // 다른게 나왔으니 다시 다른것부터 시작
                check++;
                break;
            }
            }
            if(!check){ // 길이 연장없이 한번에 끝나면
                answer.push_back(end);
                answer.push_back(start);
            }
        }
        else{   // 작은수에서 큰수로
            start = paths[i][0];    // 시작점 넣어주기
            end = paths[i][1];   // 현재 끝점 넣어주기
            for(int j = i; j < paths.size(); j++){
            if(end == paths[j][0]){ // 길이 이어져 있다면 연장하기
                end = paths[j][1];
            }
            else{   // 길이 끝났다면 answer 추가
                if(j == i){continue;}
                answer.push_back(start);
                answer.push_back(end);
                i = j - 1;
                check++;
                break;
            }
            }

            if(!check){ // 길이 연장없이 한번에 끝나면
                answer.push_back(start);
                answer.push_back(end);
            }
        }
        if(end == paths[paths.size()-1][0] || end == paths[paths.size()-1][1]){
            break;
        }
    }

    cout << "answer : ";
    for (int i : answer){
        cout << i << ", ";
    }
    cout << endl;
    return answer;
}

int main(){
    vector<vector< int> > paths;
    vector< int> tem;
    tem.push_back(1);
    tem.push_back(2);
    paths.push_back(tem);

    tem.clear();
    tem.push_back(2);
    tem.push_back(3);
    paths.push_back(tem);

    tem.clear();
    tem.push_back(3);
    tem.push_back(4);
    paths.push_back(tem);

    tem.clear();
    tem.push_back(8);
    tem.push_back(7);
    paths.push_back(tem);

    tem.clear();
    tem.push_back(7);
    tem.push_back(6);
    paths.push_back(tem);


    solution(paths);    // 1,4,8,6

    paths.clear();

    tem.clear();
    tem.push_back(1);
    tem.push_back(2);
    paths.push_back(tem);

    tem.clear();
    tem.push_back(4);
    tem.push_back(5);
    paths.push_back(tem);

    tem.clear();
    tem.push_back(10);
    tem.push_back(9);
    paths.push_back(tem);

    tem.clear();
    tem.push_back(3);
    tem.push_back(4);
    paths.push_back(tem);

    solution(paths);    // 1,2,3,5,10,9

    
}
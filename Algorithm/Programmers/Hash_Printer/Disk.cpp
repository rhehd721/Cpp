// 제한 사항
// jobs의 길이는 1 이상 500 이하입니다.
// jobs의 각 행은 하나의 작업에 대한 [작업이 요청되는 시점, 작업의 소요시간] 입니다.
// 각 작업에 대해 작업이 요청되는 시간은 0 이상 1,000 이하입니다.
// 각 작업에 대해 작업의 소요시간은 1 이상 1,000 이하입니다.
// 하드디스크가 작업을 수행하고 있지 않을 때에는 먼저 요청이 들어온 작업부터 처리합니다.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector< vector<int> > jobs) {
    int answer = 0;
    // [[0, 3], [1, 9], [2, 6]] [요청되는 시점, 소요되는 시간]
    vector<int> start;
    vector<int> time;

    sort(jobs.begin(), jobs.end()); // 요청시간이 짧은 순서대로 정렬

    for(vector<int> i : jobs){
        start.push_back(i.at(0));
        time.push_back(i.at(1));
    }

    

    

    // cout << "\nstart : " ;
    // for (int i : start){
    //     cout << i << ", ";
    // }
    // cout << "\ntime : " ;
    // for (int i : time){
    //     cout << i << ", ";
    // }

    cout << "\nanswer : " << answer % jobs.size() << endl << endl;
    return answer % jobs.size();  // 9
}

int main(){
    vector< vector<int> > jobs;
    vector<int> a; vector<int> b; vector<int> c;

    a.push_back(0); a.push_back(3);

    b.push_back(1); b.push_back(9);

    c.push_back(2); c.push_back(6);

    jobs.push_back(a); jobs.push_back(b); jobs.push_back(c);

    solution(jobs); // 9
}
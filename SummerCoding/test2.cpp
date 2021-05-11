#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<int> solution(vector<int> t, vector<int> r) {
    vector<int> answer; // t 들어온시각 // r 등급
    vector<int> T = t;

    vector<int> sorted_t(t.size());
    vector<int> sorted_r(t.size());
    vector<int> sorted_idx(t.size());

    // 최소시간과 최대시간
    sort(t.begin(), t.end());
    int t_min = t[0];
    int t_max = t[t.size()-1];

    int index(0);
    for(int time(t_min); time <= t_max; time++){
        for(int idx(0); idx < T.size(); idx++){
            if(time == T[idx]){ // 들어온 시간대로 등급과 함께 저장
                sorted_t[index] = T[idx];
                sorted_r[index] = r[idx];
                sorted_idx[index] = idx;
                index++;
            }
        }
    }

    int currently_idx(0);
    int next_idx(0);
    for(int i(0); i < t.size(); i++){
        
    }




    cout << "answer : ";
    for (int i : answer){
        cout << i << ", ";
    }
    cout << endl;
    return answer;
}


int main(){
    vector<int> t;
    t.push_back(0);
    t.push_back(1);
    t.push_back(3);
    t.push_back(0);
    vector<int> r;
    r.push_back(0);
    r.push_back(1);
    r.push_back(2);
    r.push_back(3);

    solution(t,r);  // result [0, 1, 3, 2]

    t.clear();
    r.clear();

    t.push_back(7);
    t.push_back(6);
    t.push_back(8);
    t.push_back(1);

    r.push_back(0);
    r.push_back(1);
    r.push_back(2);
    r.push_back(3);

    solution(t,r);	// result[3, 1, 0, 2]
    

}
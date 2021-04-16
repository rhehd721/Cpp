// 제한사항
// 과학자가 발표한 논문의 수는 1편 이상 1,000편 이하입니다.
// 논문별 인용 횟수는 0회 이상 10,000회 이하입니다.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int Paper(citations.size());    // 총 투고한 논문
    
    sort(citations.begin(), citations.end());   // 논문 인용수 정렬
    vector<int> Sort_citations = citations;     // 정렬된 citations
    // cout << "Sort_citations : ";
    // for (int i : Sort_citations){
    //     cout << i << ", ";
    // }
    // cout << endl;
    citations.erase(unique(citations.begin(), citations.end()), citations.end());   // 중복제거
    // cout << "citations : ";
    // for (int i : citations){
    //     cout << i << ", ";
    // }
    // cout << endl;

    for (int h : citations){
        int cnt_Big(0); // h 보다 많이 인용된 횟수
        int cnt_Small(0);   // h 보다 적게 인용된 횟수
        for(int j : Sort_citations){
            if(h <= j){ // 특정 횟수 이상 인용된 논문의 수
                cnt_Big++;
            }
            else{
                cnt_Small++;
            }
        }
        cout << h << '<' << cnt_Big << '<' << cnt_Small << endl;
        if(h <= cnt_Big){   // h번 이상 인용되었는가
            if(h > cnt_Small){ // h번 이하?미만? 인용되지 않은 논문이 존재하는가
                answer = h;
            }
        }
        else{
            break;
        }
    }

    cout << answer << endl;
    return answer;
}

int main(){
    vector<int> citations;
    citations.push_back(3);
    citations.push_back(0);
    citations.push_back(6);
    citations.push_back(1);
    citations.push_back(5);

    solution(citations);    // 3
}
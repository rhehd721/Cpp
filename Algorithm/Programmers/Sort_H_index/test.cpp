#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(), greater<int>());   // 내림차순

    for (int i = 0; i < citations.size(); ++i) {    // citations 요소 탐색
        if (citations[i] < i + 1) {
            cout << "i : " << i << endl;
            return i;
        }
    }


    cout << "citations.size() : " << citations.size() << endl;
    return citations.size();    // 도는동안 값을 구하지 못했다면 size 리턴
}
int main(){
    vector<int> citations;
    citations.push_back(3);
    citations.push_back(0);
    citations.push_back(6);
    citations.push_back(1);
    citations.push_back(5);

    solution(citations);    // 3

    citations.clear();
    citations.push_back(0);
    citations.push_back(0);
    citations.push_back(0);
    solution(citations);    // 0

    citations.clear();
    citations.push_back(12);
    citations.push_back(11);
    citations.push_back(10);
    citations.push_back(9);
    citations.push_back(8);
    citations.push_back(1);
    solution(citations);    // 5

    citations.clear();
    citations.push_back(6);
    citations.push_back(6);
    citations.push_back(6);
    citations.push_back(6);
    citations.push_back(6);
    citations.push_back(1);
    solution(citations);    // 5

    citations.clear();
    citations.push_back(4);
    citations.push_back(4);
    citations.push_back(4);
    solution(citations);    // 3

}
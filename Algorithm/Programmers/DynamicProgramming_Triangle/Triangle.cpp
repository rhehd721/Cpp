// 제한사항
// 삼각형의 높이는 1 이상 500 이하입니다.
// 삼각형을 이루고 있는 숫자는 0 이상 9,999 이하의 정수입니다.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int> > triangle) {
    int answer(0);
    int index(0);   // 자기자신 또는 +1

    int Max_Size(1);

    for(int i(0); i < triangle.size(); i++){
        Max_Size *= triangle[i].size();
    }

    vector<int> Sum_List(Max_Size);

    for (int i(0); i < Max_Size; i++){
        // Sum_List->push_back(??);
    }

    sort(Sum_List.begin(), Sum_List.end());

    answer = Sum_List[Sum_List.size() - 1];

    cout << "answer : " << answer << endl;
    return answer;
}

int main(){
    vector<vector<int> > triangle;

    vector<int> tem;
    tem.push_back(7);
    triangle.push_back(tem);

    tem.clear();
    tem.push_back(3);
    tem.push_back(8);
    triangle.push_back(tem);

    tem.clear();
    tem.push_back(8);
    tem.push_back(1);
    tem.push_back(0);
    triangle.push_back(tem);

    tem.clear();
    tem.push_back(2);
    tem.push_back(7);
    tem.push_back(4);
    tem.push_back(4);
    triangle.push_back(tem);

    tem.clear();
    tem.push_back(4);
    tem.push_back(5);
    tem.push_back(2);
    tem.push_back(6);
    tem.push_back(5);
    triangle.push_back(tem);
    
    solution(triangle); // 30
}
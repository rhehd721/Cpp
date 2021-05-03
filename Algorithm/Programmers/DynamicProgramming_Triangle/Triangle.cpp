// 제한사항
// 삼각형의 높이는 1 이상 500 이하입니다.
// 삼각형을 이루고 있는 숫자는 0 이상 9,999 이하의 정수입니다.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int> > triangle) {
    int answer = 0;

    // for(vector<int> Num : triangle){
    //     sort(Num.begin(), Num.end(), greater<int>()); // 내림차순 정렬
    //     for(int i = 0; i < Num.size(); i++){
    //         cout << Num[i] << ", ";
    //     }
    //     cout << endl;
    // }

    int Max_Num(0);

    for(vector<int> Num : triangle){
        sort(Num.begin(), Num.end(), greater<int>()); // 내림차순 정렬
        Max_Num += Num[0];
    }
    

    answer = Max_Num;

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
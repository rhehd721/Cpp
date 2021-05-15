// 제한사항
// 삼각형의 높이는 1 이상 500 이하입니다.
// 삼각형을 이루고 있는 숫자는 0 이상 9,999 이하의 정수입니다.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int Find_MaxNum(vector<vector<int> > & triangle, int Height, int index, int Max_Height, queue<int> & result, int Currently_num){
    Currently_num += triangle[Height][Height];
    if(Height == Max_index){
        result.push(Currently_num);
    }
    else{
        // Find_MaxNum(vector<int> & Num, int index, int Max_index, vector<int> & result, int Currently_num)
    }

    return 0;
}

int solution(vector<vector<int> > triangle) {
    int answer(0);

    queue<int> result;  // 만들수 있는 모든 숫자??
    
    Find_MaxNum(triangle, 0 ,0, triangle.size(), result, 0);
    
    answer = result.back();

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
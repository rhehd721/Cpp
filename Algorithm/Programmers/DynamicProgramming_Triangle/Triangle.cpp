// 제한사항
// 삼각형의 높이는 1 이상 500 이하입니다.
// 삼각형을 이루고 있는 숫자는 0 이상 9,999 이하의 정수입니다.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// int solution2(vector<vector<int> > triangle, int index, int num, vector<int> Sum_List, int List_idx){
//     if(index < triangle.size()){
//         triangle[index][index];
//         triangle[index][index + 1];
//         solution2(triangle, ++index, num);
//     }
//     else{
//         return 0;
//     }
// }

int solution(vector<vector<int> > triangle) {
    int answer(0);

    // triangle의 요소들로 만들 수 있는 숫자의 갯수
    int Max_Size(1);
    for(int i(0); i < triangle.size(); i++){
        Max_Size *= triangle[i].size();
    }
    vector<int> Sum_List(Max_Size);
    
    // triangle의 요소로 만들 수 있는 모든 숫자조합을 넣어주기
    Max_Size = 0;
    int List_idx(0);

    // while(1){
    //     int tem(0);
    //     for (int tr(0); tr < triangle.size(); tr++){
    //         int index(0);   // 자기자신 또는 +1
    //         tem += triangle[tr][index];

    //         // triangle[tr][index + 1];
    //         // triangle[tr][index];
    //     }

    //     // Sum_List[Max_Size++] = ?

    //     if( Max_Size ==  Sum_List.size()){   // 모든 숫자를 만들었다면 빠져나오기
    //         break;
    //     }
    // }
    
    
    // 만들어진 숫자 중 최대숫자 찾아기
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
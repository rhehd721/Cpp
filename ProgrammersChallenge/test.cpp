// 제한사항
// v는 세 점의 좌표가 들어있는 2차원 배열입니다.
// v의 각 원소는 점의 좌표를 나타내며, 좌표는 [x축 좌표, y축 좌표] 순으로 주어집니다.
// 좌표값은 1 이상 10억 이하의 자연수입니다.
// 직사각형을 만드는 데 필요한 나머지 한 점의 좌표를 [x축 좌표, y축 좌표] 순으로 담아 return 해주세요.


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<int> solution(vector<vector<int> > v) {
    vector<int> ans;

    vector<int> tem_x;
    vector<int> tem_y;

    for (vector<int> i : v){
        tem_x.push_back(i[0]);
        tem_y.push_back(i[1]);
    }
    sort(tem_x.begin(), tem_x.end());
    sort(tem_y.begin(), tem_y.end());

    if(tem_x[0] == tem_x[1]){
        ans.push_back(tem_x[2]);
    }
    else{
        ans.push_back(tem_x[0]);
    }
    if(tem_y[0] == tem_y[1]){
        ans.push_back(tem_y[2]);
    }
    else{
        ans.push_back(tem_y[0]);
    }

    for (int i : ans){
        cout << i << ", ";
    }
    cout << endl;
    
    return ans;
}

int main(){
    vector<vector<int> > v;
    vector<int> a;
    a.push_back(1);
    a.push_back(4);
    v.push_back(a);
    a.clear();

    a.push_back(3);
    a.push_back(4);
    v.push_back(a);
    a.clear();

    a.push_back(3);
    a.push_back(10);
    v.push_back(a);
    a.clear();

    solution(v);    // [1, 10]
    v.clear();

    a.push_back(1);
    a.push_back(1);
    v.push_back(a);
    a.clear();

    a.push_back(2);
    a.push_back(2);
    v.push_back(a);
    a.clear();

    a.push_back(1);
    a.push_back(2);
    v.push_back(a);
    a.clear();

    solution(v);    // [2, 1]

}
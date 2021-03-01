// 제한사항
// clothes의 각 행은 [의상의 이름, 의상의 종류]로 이루어져 있습니다.
// 스파이가 가진 의상의 수는 1개 이상 30개 이하입니다.
// 같은 이름을 가진 의상은 존재하지 않습니다.
// clothes의 모든 원소는 문자열로 이루어져 있습니다.
// 모든 문자열의 길이는 1 이상 20 이하인 자연수이고 알파벳 소문자 또는 '_' 로만 이루어져 있습니다.
// 스파이는 하루에 최소 한 개의 의상은 입습니다.

#include<iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string> > clothes) {
    int answer = 0;

    
    



    return answer;
}

int main(){
    vector<vector<string> > clothes;
    clothes.push_back({"yellowhat", "headgear"});
    clothes.push_back({"bluesunglasses", "eyewear"});
    clothes.push_back({"green_turban", "headgear"});

    solution(clothes);

    return 0;
}


// vector<vector<int>> vct_1;
// vector<int> vctTemp;
// vct_1.resize(5);
// for(int i=0; i<5; ++i)
//     vct_1[i] = vctTemp;
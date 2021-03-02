// 제한사항
// clothes의 각 행은 [의상의 이름, 의상의 종류]로 이루어져 있습니다.
// 스파이가 가진 의상의 수는 1개 이상 30개 이하입니다.
// 같은 이름을 가진 의상은 존재하지 않습니다.
// clothes의 모든 원소는 문자열로 이루어져 있습니다.
// 모든 문자열의 길이는 1 이상 20 이하인 자연수이고 알파벳 소문자 또는 '_' 로만 이루어져 있습니다.
// 스파이는 하루에 최소 한 개의 의상은 입습니다.

// 풀이
// 1. 옷의 종류별로 몇개가 존재하는지 구한다
// 2. 만약 옷의 종류가 한개라면 답은 그 종류의 총 갯수이다.
// 3. 만약 옷의 갯수가 한개가 아니라면 전체합 + 종류* 이다.
// 1개, 2개, 3개, 4개 ... n개

#include<iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string> > clothes) {
    int answer = 0;
    int check = 0;

    // cout << clothes[0][0] << endl;

    vector<string> ClothesList;
    
    // 어떤 종류의 의상이 있는지 확인
    for (int i = 0; i < clothes.size(); i++){
        if (i == 0){
            ClothesList.push_back(clothes[i][clothes[i].size()-1]);
        }
        else{
            for (string inList : ClothesList){
                if (inList == clothes[i][clothes[i].size()-1]){ // ClothesList안에 같은 종류의 의상이 있다면 check++
                    check++;
                }
            }
            if (check == 0){    // 새로운 종류라면 List에 추가
                ClothesList.push_back(clothes[i][clothes[i].size()-1]);
            }
            else{
                check = 0;
            }
        }
    }

    // cout << ClothesList.size() << endl;

    vector<int> NumberofEachType;
    check = 0;

    int index = -1;

    for (string inList : ClothesList){  // 옷종류
        index++;
        check = 0;
        for (int i = 0; i < clothes.size(); i++){   // 전체 arr
             if (inList == clothes[i][clothes[i].size()-1]){    // 옷종류애 해당하는 arr를 만나면
                if(check == 0){ // 처음에는 push_back
                    NumberofEachType.push_back(clothes[i].size()-1);
                    check++;
                }
                else{   // 두번째부턴 값 추가로 더하기
                    NumberofEachType[index] += clothes[i].size()-1;
                }
                
             }
        }
    }

    // cout << NumberofEachType.size() << endl;
    int result = 1;

    if (NumberofEachType.size() == 1){
        answer += NumberofEachType[0];
        return answer;
    }
    else if (NumberofEachType.size() == 2){
        for (int i : NumberofEachType){
            result *= i;
            answer += i;
        }
        // result *= NumberofEachType.size()-1;
        return result + answer;
    }
    else{
        for (int i : NumberofEachType){
            result *= i+1;
            answer += i;
        }
        // result *= NumberofEachType.size()-1;
        return result + answer;

    }

    return -1;
}

int main(){
    vector<vector<string> > clothes;
    vector<string> tem;
    tem.push_back("yellowhat");
    tem.push_back("headgear");
    clothes.push_back(tem);
    tem.clear();

    tem.push_back("bluesunglasses");
    tem.push_back("eyewear");
    clothes.push_back(tem);
    tem.clear();

    tem.push_back("green_turban");
    tem.push_back("headgear");
    clothes.push_back(tem);
    tem.clear();

    cout << solution(clothes) << endl;

    return 0;
}
// [제한사항]
// orders 배열의 크기는 2 이상 20 이하입니다.
// orders 배열의 각 원소는 크기가 2 이상 10 이하인 문자열입니다.
// 각 문자열은 알파벳 대문자로만 이루어져 있습니다.
// 각 문자열에는 같은 알파벳이 중복해서 들어있지 않습니다.
// course 배열의 크기는 1 이상 10 이하입니다.
// course 배열의 각 원소는 2 이상 10 이하인 자연수가 오름차순으로 정렬되어 있습니다.
// course 배열에는 같은 값이 중복해서 들어있지 않습니다.
// 정답은 각 코스요리 메뉴의 구성을 문자열 형식으로 배열에 담아 사전 순으로 오름차순 정렬해서 return 해주세요.
// 배열의 각 원소에 저장된 문자열 또한 알파벳 오름차순으로 정렬되어야 합니다.
// 만약 가장 많이 함께 주문된 메뉴 구성이 여러 개라면, 모두 배열에 담아 return 하면 됩니다.
// orders와 course 매개변수는 return 하는 배열의 길이가 1 이상이 되도록 주어집니다.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course){
    vector< string > answer;

    

    




    for (string i : answer){
        cout << i << ", ";
    }
    cout << endl;
    return answer;
}

int main(){
    vector < string > orders;
    vector < int > course;
    orders.push_back("ABCFG");
    orders.push_back("AC");
    orders.push_back("CDE");
    orders.push_back("ACDE");
    orders.push_back("BCFG");
    orders.push_back("ACDEH");

    course.push_back(2);
    course.push_back(3);
    course.push_back(4);

    solution(orders, course);   // ["AC", "ACDE", "BCFG", "CDE"]
    orders.clear();
    course.clear();


    orders.push_back("ABCDE");
    orders.push_back("AB");
    orders.push_back("CD");
    orders.push_back("ADE");
    orders.push_back("XYZ");
    orders.push_back("XYZ");
    orders.push_back("ACD");

    course.push_back(2);
    course.push_back(3);
    course.push_back(5);

    solution(orders, course);   // ["ACD", "AD", "ADE", "CD", "XYZ"]
    orders.clear();
    course.clear();

    orders.push_back("XYZ");
    orders.push_back("XWY");
    orders.push_back("WXA");

    course.push_back(2);
    course.push_back(3);
    course.push_back(4);

    solution(orders, course);   // ["WX", "XY"]

}
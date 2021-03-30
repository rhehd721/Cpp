// 제한사항
// 무인도에 갇힌 사람은 1명 이상 50,000명 이하입니다.
// 각 사람의 몸무게는 40kg 이상 240kg 이하입니다.
// 구명보트의 무게 제한은 40kg 이상 240kg 이하입니다.
// 구명보트의 무게 제한은 항상 사람들의 몸무게 중 최댓값보다 크게 주어지므로 사람들을 구출할 수 없는 경우는 없습니다.
// max = 2

// 아래 풀이방법은 정확도는 100이나 효율성이 떨어지는 코드입니다.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int weight(0);
    int check(0);

    sort(people.begin(), people.end()); // 오름차순

    while(1){
        if(people.size() > 1){
            for(int j = people.size() - 2; j >= 0; --j){
                weight = people.back() + people[j];
                // cout << "weight : " <<  weight << endl;
                if(weight <= limit){
                    people.erase(people.begin() + j);
                    people.pop_back();
                    check = 1;
                    break;
                }
            }
            if(check == 1){
                check = 0;
            }
            else{
                people.pop_back();
            }
            if(people.size() == 0){
                answer++;
                break;
            }
            else{
                answer++;
            }
        }
        else{
            answer++;
            break;
        }
    }

    cout << "answer : " << answer << endl << endl;
    return answer;
}

int main(){
    vector<int> people;
    int	limit(100);
    people.push_back(70);
    people.push_back(50);
    people.push_back(80);
    people.push_back(50);
    solution(people, limit);    //3

    people.clear();
    people.push_back(70);
    people.push_back(80);
    people.push_back(50);
    solution(people, limit);    //3

}

// 제한사항
// genres[i]는 고유번호가 i인 노래의 장르입니다.
// plays[i]는 고유번호가 i인 노래가 재생된 횟수입니다.
// genres와 plays의 길이는 같으며, 이는 1 이상 10,000 이하입니다.
// 장르 종류는 100개 미만입니다.
// 장르에 속한 곡이 하나라면, 하나의 곡만 선택합니다.
// 모든 장르는 재생된 횟수가 다릅니다.

// 속한 노래가 많이 재생된 장르를 먼저 수록합니다.
// 장르 내에서 많이 재생된 노래를 먼저 수록합니다.
// 장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록합니다.

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int > GenrePlayNum;  // 장르별 재생횟수를 담을 map (재생횟수, 장르)
    map<int, string, greater<int> > GenrePlayNumSort;   // 장르별 재생횟수를 담을 map Sort (재생횟수, 장르)

    for (int idx(0); idx < genres.size(); idx++){
        if (!GenrePlayNum.count(genres[idx])){  // 처음 선택된 장르라면
            GenrePlayNum.insert(make_pair(genres[idx], plays[idx]));    // GenrePlayNum에 새로운 장르 추가
        }
        else{   // GenrePlayNum에 들어있던 장르라면
            GenrePlayNum[genres[idx]] = (GenrePlayNum.find(genres[idx]) -> second) + plays[idx];
        }
    }
    for (auto i : GenrePlayNum){    // 내람차순 sort
        GenrePlayNumSort[i.second] = i.first;
    }

    for (auto i : GenrePlayNumSort){    // 장르 순회
        // cout << "획인 : " << i.second << endl;
        int top1(0);
        int top2(0);
        int num(0);
        int top1idx(0);
        int top2idx(0);
        int check(0);
        for(int idx(0); idx < genres.size(); idx++){
            if (i.second == genres[idx]){   // 선택된 장르가 나타난다면
                num = plays[idx];
                // cout << "num : " << num << endl;
            }

            if (num > top2 && num > top1){    // 둘보다 크다면
                check = 0;  // 새로운 최고점수가 나왔으니 초기화

                top2 = top1;
                top2idx = top1idx;

                top1 = num;
                top1idx = idx;
                // cout << "top1 top2 : " << top1 << ", " << top2 << ", " << top1idx << ", " << top2idx << ", " << endl;
            }
            else if (num > top2 && num < top1){    // 둘 사이의 값이라면
                top2 = num;
                top2idx = idx;
            }
            else if (num == top1){  // 같은 재생횟수를 가진 음악
                if (check == 1){
                    continue;
                }
                else{
                    top2 = num;
                    top2idx = idx;
                    check++;
                }
            }
            num = 0;
            
        }
        if (top2 == 0){ // 한곡만 존재
            answer.push_back(top1idx);
        }
        else{   // 두곡이상 존재
            answer.push_back(top1idx);
            answer.push_back(top2idx);
        }
    }

    for (auto i : answer){
        cout << i << ", ";
    }
    cout << endl;

    return answer;
}

int main(){
    vector<string> genres;  // 고유번호가 i인 노래의 장르
    vector<int> plays;  // 고유번호가 i인 노래가 재생된 횟수

    genres.push_back("classic");
    genres.push_back("pop");
    genres.push_back("classic");
    genres.push_back("classic");
    genres.push_back("pop");

    plays.push_back(500);   // 0
    plays.push_back(600);   // 1
    plays.push_back(150);   // 2
    plays.push_back(800);   // 3
    plays.push_back(2500);   // 4

    solution(genres, plays); // [4, 1, 3, 0]

    genres.clear();
    plays.clear();

    genres.push_back("classic");
    genres.push_back("classic");
    genres.push_back("classic");
    genres.push_back("pop");

    plays.push_back(500);
    plays.push_back(150);
    plays.push_back(800);
    plays.push_back(2500);

    solution(genres, plays);    // 3,2,0

    genres.clear();
    plays.clear();

    genres.push_back("classic");
    genres.push_back("classic");
    genres.push_back("classic");
    genres.push_back("classic");
    genres.push_back("classic");
    genres.push_back("classic");
    genres.push_back("pop");
    genres.push_back("pop");
    genres.push_back("pop");
    genres.push_back("pop");
    genres.push_back("pop");
    genres.push_back("pop");

    plays.push_back(500);
    plays.push_back(500);
    plays.push_back(200);
    plays.push_back(500);
    plays.push_back(200);
    plays.push_back(200);

    plays.push_back(2500);
    plays.push_back(5000);
    plays.push_back(5000);
    plays.push_back(5000);
    plays.push_back(2500);
    plays.push_back(2500);

    solution(genres, plays);
}
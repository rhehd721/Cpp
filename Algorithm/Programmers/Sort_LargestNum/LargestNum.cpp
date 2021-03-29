// 제한 사항
// numbers의 길이는 1 이상 100,000 이하입니다.
// numbers의 원소는 0 이상 1,000 이하입니다.
// 정답이 너무 클 수 있으니 문자열로 바꾸어 return 합니다
// 0, 1~9, 10~99. 100~999, 1000
// 0 = end
// 1000 = end - 1
// 999, 99, 9


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    vector<int> o;
    vector<int> a;
    vector<int> b;
    vector<int> c;
    vector<int> d;
    vector<string> num1;
    vector<string> num2;

    sort(numbers.begin(), numbers.end(), greater<int>());

    for (int i : numbers){
        if(i == 0){
            o.push_back(i);
        }
        else if (i >0 && i < 10){
            a.push_back(i);
        }
        else if (i > 10 && i < 100){
            b.push_back(i);
        }
        else if (i > 100 && i < 1000){
            c.push_back(i);
        }
        else{
            d.push_back(i);
        }
    }
    sort(d.begin(), d.end());

    while(1){
        for(int i = 9; i > 0; i --){
            int i_num = 0;  // 갯수
            int ii_num = 0;  // 갯수
            int iii_num = 0;  // 갯수
            string s_num = "";   // 해당 숫자
            string ss_num = "";
            string sss_num = "";

            // 9 를 찾아라      // 3(3) 34(1) 335(2) 321(4)
            s_num = s_num + to_string(i);
            i_num = count(a.begin(), a.end(), stoi(s_num));
            // for (int z = 0; z < i_num; z++){
            //     answer += s_num;
            // }

            // 99 ~ 90 을 찾아라
            for(int j = 9; j >= 0; j --){
                
                ss_num = s_num + to_string(j);
                ii_num = count(b.begin(), b.end(), stoi(ss_num));
                
                // 999 ~ 990 을 찾아라
                for(int k = 9; k >= 0; k --){
                    if(j > i && k > j){}
                    sss_num = ss_num + to_string(k);
                    iii_num = count(c.begin(), c.end(), stoi(sss_num));
                    
                    if (j >= i && k >= j){  // 미리 넣기 ex. 333, 334, 345, 344
                        for (int z = 0; z < iii_num; z++){
                            answer += sss_num;
                            iii_num = 0;
                        }
                    }
                    else{   // 311, 331
                        for (int z = 0; z < iii_num; z++){
                            num2.push_back(sss_num);
                        }
                    }
                }
                if(j >= i){  // 미리 넣기 ex. 34, 33
                    for (int z = 0; z < ii_num; z++){
                        answer += ss_num;
                    }
                }
                else{

                }
                
            }

        }

        for (int z = 0; z < d.size(); z++){
            answer += to_string(d.at(z));
        }
        for (int z = 0; z < o.size(); z++){
            answer += "0";
        }
        break;
    }

    cout << "answer : " << answer << endl << endl; 
    return answer;
}


int main(){
    cout << "1 번 문제 \n";
    vector<int> numbers;
    numbers.push_back(6);
    numbers.push_back(10);
    numbers.push_back(2);
    solution(numbers);  //	6210

    cout << "2 번 문제 \n";
    numbers.clear();
    numbers.push_back(3);
    numbers.push_back(30);
    numbers.push_back(34);
    numbers.push_back(5);
    numbers.push_back(9);
    solution(numbers);  //	9534330     // 9533430

}
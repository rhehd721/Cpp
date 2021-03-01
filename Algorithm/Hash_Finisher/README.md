# Hash - Finisher

## 최우수 풀이

```cpp
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    for(int i=0;i<completion.size();i++)
    {
        if(participant[i] != completion[i])
            return participant[i];
    }
    return participant[participant.size() - 1];
    //return answer;
}
```

## 두번째 우수 풀이
```cpp
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> strMap;
    for(auto elem : completion)
    {
        if(strMap.end() == strMap.find(elem))
            strMap.insert(make_pair(elem, 1));
        else
            strMap[elem]++;
    }

    for(auto elem : participant)
    {
        if(strMap.end() == strMap.find(elem))
        {
            answer = elem;
            break;
        }
        else
        {
            strMap[elem]--;
            if(strMap[elem] < 0)
            {
                answer = elem;
                break;
            }
        }
    }
    return answer;
}
```
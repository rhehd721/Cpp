# Sort - H_idx

# 최우수 풀이
```cpp
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(), greater<int>());   // 내림차순

    for (int i = 0; i < citations.size(); ++i) {    // citations 요소 탐색
        if (citations[i] < i + 1) {
            return i;
        }
    }

    return citations.size();    // 도는동안 값을 구하지 못했다면 size 리턴
}
```
# Stack_Queue - Truck

## 최우수 풀이

```cpp
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    int tot_w = 0;

    int t_front = 0;
    int t_cur = 0;

    int sec = 0;

    queue <int> q;

    while (t_front != truck_weights.size()) {
        if (!q.empty() && (sec - q.front() == bridge_length)) {
            tot_w -= truck_weights[t_front];
            ++t_front;
            q.pop();
        }
        if (t_cur != truck_weights.size() && tot_w + truck_weights[t_cur] <= weight) {
            tot_w += truck_weights[t_cur];
            ++t_cur;
            q.push(sec);
        }
        ++sec;
    }

    answer = sec;

    return answer;
}
```

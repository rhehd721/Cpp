# Heap - Spicy

## 최우수 풀이

```cpp
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int needHot;
    priority_queue<int,vector<int>,greater<int>> pq (scoville.begin(),scoville.end());

    while(pq.top()<K) {
        if(pq.size()==1) return answer = -1;
        needHot=pq.top(); pq.pop();
        pq.push(needHot+pq.top()*2);
        pq.pop(); answer++;
    }

    return answer;
}
```

## 나의 첫번째 풀이 (정확성 O, 효율성 X)
```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    int NewScoville = 0;

    while(1){
        sort(scoville.begin(), scoville.end());
        if (scoville[0] >= K){  // 모든 음식이 K를 넘겼을 경우
            break;
        }
        else{   // 모든 음식이 K를 넘지 못했기 때문에 새로운 음식을 만든다.
            if (scoville.size() >= 2){  // 섞을 음식이 남았을 경우
            NewScoville = scoville[0] + ( scoville[1] * 2 );    // 새로만든 스코빌 지수
            scoville.erase(scoville.begin(), scoville.begin() + 2); // 합성에 사용된 음식 삭제
            scoville.push_back(NewScoville);    // 새로운 음식 추가
            ++answer;   // 음식을 섞었으므로 횟수 증가!
            }
            else{   // 더이상 합성할 음식이 없으므로 -1 반환
                answer = -1;
                break;
            }
        }
    }
    cout << answer << endl;
    return answer;
}
```

## 두번째 풀이 (정확성 O, 효율성 O)
```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    int NewScoville = 0;

    priority_queue < int, vector<int> , greater<int> > pqscovile;

    for (int i : scoville){
        pqscovile.push(i);
    }

    while(1){
        if (pqscovile.top() >= K){  // 모든 음식이 K를 넘겼을 경우
            break;
        }
        else{   // 모든 음식이 K를 넘지 못했기 때문에 새로운 음식을 만든다.
            if (pqscovile.size() >= 2){  // 섞을 음식이 남았을 경우
            NewScoville += pqscovile.top();
            pqscovile.pop();
            NewScoville += ( pqscovile.top() * 2 );    // 새로만든 스코빌 지수
            pqscovile.pop();
            pqscovile.push(NewScoville);    // 새로운 음식 추가
            ++answer;   // 음식을 섞었으므로 횟수 증가!
            NewScoville = 0;
            }
            else{   // 더이상 합성할 음식이 없으므로 -1 반환
                answer = -1;
                break;
            }
        }
    }
    cout << answer << endl;
    return answer;
}
```

## queue

### 우선순위 큐 선언
```cpp
// 기본형
priority_queue<T, Container, Compare>
```
```cpp
// Ex
priority_queue < int, vector<int> , greater<int> > pq;  // greater<int> 오름차순 정렬
```

### priority_queue 멤버 함수
1. .size();
    - 원소의 개수를 반환합니다.
2. .top();
    - access top element
3. .push();
    - insert element
4. .pop();
    - delete top element
5. while( !pq.empty() ) pq.pop();
    - 초기화 == clear()
6. empty()
    - 비어있으면 true 아니면 false를 반환
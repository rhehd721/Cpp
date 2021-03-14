// 제한 조건
// bridge_length는 1 이상 10,000 이하입니다.
// weight는 1 이상 10,000 이하입니다.
// truck_weights의 길이는 1 이상 10,000 이하입니다.
// 모든 트럭의 무게는 1 이상 weight 이하입니다.

#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer(0);
    int on_bridge(0);
    int index(0);
    vector<int> truck_Progress;
    int pop(0);

    while(1){
        answer++;
        if(truck_Progress.size()){  // 다리를 지난 트럭 제거
            if (truck_Progress[pop] == bridge_length){
                on_bridge -= truck_weights[pop];
                if (pop == truck_weights.size() - 1){
                    break;
                }
                pop++;
            }
        }
        if ((on_bridge + truck_weights[index] ) <= weight){    // 하중이 된다면 다리위 트럭 추가
            if (index < truck_weights.size()){  // 대기중 트럭 추가
                on_bridge += truck_weights[index++];
                for (int i(pop); i < truck_Progress.size(); i++){
                    truck_Progress[i]++;
                }
                truck_Progress.push_back(1);
            }
            else{   // 하중은 되지만 추가할 트럭이 없는 경우
                for (int i(pop); i < truck_Progress.size(); i++){
                    truck_Progress[i]++;
                }
            }
        }
        else{   // 하중이 안된다면 지나간 거리만 증가
            for (int i(pop); i < truck_Progress.size(); i++){
                truck_Progress[i]++;
            }
        }
    }

    cout << endl << answer << endl;
    return answer;
}

int main(){
    int bridge_length(2);
    int	weight(10);
    vector<int>	truck_weights;
    truck_weights.push_back(7);
    truck_weights.push_back(4);
    truck_weights.push_back(5);
    truck_weights.push_back(6);
    
    solution(bridge_length, weight, truck_weights); // 8

    bridge_length = 100;
    weight = 100;
    truck_weights.clear();
    truck_weights.push_back(10);

    solution(bridge_length, weight, truck_weights); // 101

    truck_weights.push_back(10);
    truck_weights.push_back(10);
    truck_weights.push_back(10);
    truck_weights.push_back(10);
    truck_weights.push_back(10);
    truck_weights.push_back(10);
    truck_weights.push_back(10);
    truck_weights.push_back(10);
    truck_weights.push_back(10);

    solution(bridge_length, weight, truck_weights); // 110
}
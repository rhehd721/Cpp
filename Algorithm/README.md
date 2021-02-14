# Algorithm
[참고](https://github.com/rhehd721/Bit_Data-structure)

## Big_O(빅오)

1. O(1) : 처리하는 데이터양과 상관없이 일정한 실행시간 Ex. 스택에서 Push, Pop
2. O(logN) : 처리해야 하는 데이터가 증가할수록 실행 시간도 약간씩 증가하는 알고리즘 단, 실행 증가폭은 logN Ex. 이진트리
3. O(N) : 처리하는 데이터양과 비례해 실행 시간도 증가 Ex. for 문
4. O(NlogN) : 처리할 데이터양보다 실행 시간이 좀 더 빠르게 증가 Ex. 퀵 정렬(quick sort), 병합정렬(merge sort), 힙 정렬(heap Sort)
5. O(N^2) : 데이터양의 제곱만큼 실행시간 증가 Ex. 이중 for 문, 삽입정렬(insertion sort), 거품정렬(bubble sort), 선택정렬(selection sort)
6. O(N^3) : 삼중 for문
6. O(2^N) : 데이터양의 따라 2^N만큼 실행시간 증가 Ex. 피보나치 수열

---

## Linked List

### Singly Linked List
```cpp
struct SinglyLinkedList {
     char Data;
     struct SinglyLinkedList * Next;
     };
```

단일 링크드 리스트의 경우 배열과 비슷하게 볼 수 있지만 배열과는 다르게 중간에 그 크기를 변경할 수 있다. Ex. Stack(LIFO : Last In First Out)

### Double Linked List
```cpp
struct DoubleLinkedList {
     char Data;
     struct DoubleLinkedList * Next;
     struct DoubleLinkedList * Prev;
     };
```
Ex. Queue(FIFO : First In First Out)

---

## Tree

### 용어정리
1. Root Node : 제일 상위의 노드
2. Degree : 한 노드에 연결된 서브 트리의 갯수
3. Parent Node : 현재 노드에 연결된 상위 노드
4. Child Node : 현재 노드의 아래에 있는 노드
5. Sibling Node : 같은 부모를 가진 노드
6. Leaf Node : 가장 하위의 노드
7. Level : 루트노드부터 해당 노드까지 방문한 총 노드의 수
8. Height, Depth : 트리의 최대 레벨 수

### 순회 알고리즘
1. 전위 순회(Pre-Order Traverse)
2. 중위 순회(In-Order Traverse)
3. 후위 순회(Post-Order Traverse)
4. 단계 순회(Level-Order Traverse)

### Binary Tree
자식 노드가 2개 이하인 트리
```cpp
struct BinaryTree {
     char Data;
     struct BinaryTree * Left;
     struct BinaryTree * Right;
     };
```
1. 왼쪽으로 기울어진 이진 트리
2. 오른쪽으로 기울어진 이진 트리
3. 완전 이진 트리 : 모든 노드에 자식 노드가 하나도 없거나 2개의 자식을 가진 이진 트리
4. 정 이진 트리 : 완전 이진 트리에서 리프 노드들의 레벨이 같은 이진 트리

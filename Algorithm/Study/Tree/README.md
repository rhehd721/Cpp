# Tree

## 용어 정리
1. 루트 노드(root node) : 연결된 노드가 한 군데로 모이는 가장 상위의 노드
2. 차수(degree) : 한 노드에 연결된 서브 트리의 갯수
3. 부모 노드(parent node) : 현재 노드 바로 상위의 노드
4. 자식 노드(child node) : 현재 노드 바로 하위의 노드
5. 형제 노드(sibling node) : 같은 부모 노드를 가진 노드
6. 리프 노드(leaf node) : 자식 노드가 없는 노드
7. 레벨(level) : 루트 노드부터 해당 노드까지 방문한 총 노드의 갯수
8. 높이(hight), 깊이(depth) : 트리의 최대 레벨 수

## 순회
1. 전위 순회(preorder traverse)
2. 중위 순회(inorder traverse)
```c
void inorder(NODE * ptrNode){

     if(ptrNode != EndNode){
          inorder(ptrNode -> Left);
          Visit(ptrNode);
          inorder(ptrNode -> Right);
     }
}
```
3. 후위 순회(postorder traverse)
```c
void postorder(NODE * ptrNode){

     if(ptrNode != EndNode){
          postorder(ptrNode -> Left);
          postorder(ptrNode -> Right);
          Visit(ptrNode);
     }
}
```
4. 층별 순회(level order traverse)
# -*- coding: utf-8 -*- 
# // 제한사항
# // a의 길이는 2 이상 300,000 이하입니다.
# // a의 모든 수는 각각 -1,000,000 이상 1,000,000 이하입니다.
# // a[i]는 i번 정점의 가중치를 의미합니다.
# // edges의 행의 개수는 (a의 길이 - 1)입니다.
# // edges의 각 행은 [u, v] 2개의 정수로 이루어져 있으며, 이는 u번 정점과 v번 정점이 간선으로 연결되어 있음을 의미합니다.
# // edges가 나타내는 그래프는 항상 트리로 주어집니다.

def solution(a, edges):
    answer = 0
    currnt = 0

    for i in a:
        answer += i
    if(answer != 0):
        return -1
    else:
        answer = 0
        

    print(answer - 1)
    return answer - 1

a = [-5,0,2,1,2]    # 가중치
edges = [[0,1],[3,4],[2,3],[0,3]]   # 연결된 두개
solution(a, edges) # 9


a = [0,1,0]
edges = [[0,1],[1,2]]
solution(a, edges) # -1
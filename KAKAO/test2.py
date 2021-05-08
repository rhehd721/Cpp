def solution(places):
    answer = []
    P_X = []
    P_Y = []

    
    for i in places:
        for j in i:
            for k in range(0,5):
                if(j[k] == "P"):
                    P_X.append(j)
                    P_Y.append(k)
    
    for i in range(len(P_X)):
        for j in range(i, len(P_X)):
            me = 




    print(answer)
    return answer


places = [["POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"], ["POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"], ["PXOPX", "OXOXP", "OXPXX", "OXXXP", "POOXX"], ["OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"], ["PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"]]
solution(places)
# result [1, 0, 1, 1, 1]
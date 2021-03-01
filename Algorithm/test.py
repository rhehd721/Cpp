# -*- coding: utf-8 -*- 
def solution(clothes):
    answer = 0

    i = 0

    check = 0
    cloList = []

    # 옷 종류 리스트 만들기
    for i in range(0, len(clothes)):
        if (i == 0):
            cloList.append(clothes[i][len(clothes[i])-1])
        else:
            for j in cloList:
                if (j == clothes[i][len(clothes[i])-1]):
                    check = 1

            if (check == 1):
                check = 0
            else:
                cloList.append(clothes[i][len(clothes[i])-1])

    result = []
    check = -1

    # 옷 리스트당 몇개가 있는지 확인
    for i in cloList:
        result.append(0)
        check += 1
        for j in range(0, len(clo)):
            if (i == clothes[j][len(clothes[j])-1]):
                result[check] += len(clothes[j])-1

    check = 0

    for i in result:    # 하나씩 쓸때
        answer += i
    
    answer2 = 1

    for i in result:
        if(len(result) == 1):
            break
        else:
            answer2 *= i
            check += 1

    if(check != 0):
        answer2 += answer
        return answer2
    else:
        return answer



clothes = [["yellowhat", "headgear"], ["bluesunglasses", "eyewear"], ["green_turban", "headgear"]]

print(solution(clothes))

clothes = [["crowmask", "face"], ["bluesunglasses", "face"], ["smoky_makeup", "face"]]

print(solution(clothes))

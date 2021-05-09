
def solution(code, day, data):
    answer = []
    tem_dic = {}
    
    for i in data:
        s_list = i.split(" ")
        code_list = s_list[1].split("=")
        if(code_list[1] == code):
            day_list = s_list[2].split("=")
            yyyymmdd = ""
            for idx in range(0,8):
                yyyymmdd += day_list[1][idx]
                tt = ""
                if(yyyymmdd == day):
                    tt += (day_list[1][8] + day_list[1][9])
                    price_list = s_list[0].split("=")
                    tem_dic[tt] = price_list[1]
    res = sorted(tem_dic.items())
    print(res)

    for i in res:
        answer.append(int(i[1]))

    return answer

code = "012345"
day = "20190620"
data = ["price=80 code=987654 time=2019062113","price=90 code=012345 time=2019062014","price=120 code=987654 time=2019062010","price=110 code=012345 time=2019062009","price=95 code=012345 time=2019062111"]

print(solution(code, day, data))
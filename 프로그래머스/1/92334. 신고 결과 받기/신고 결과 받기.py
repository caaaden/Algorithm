from collections import Counter

def solution(id_list, report, k):
    report = list(set(report)) # 중복 제거
    report = [x.split(' ') for x in report]
    report = {i: x for i, x in enumerate(report)}
    reported = [report[x][1] for x in report]
    
    counter = Counter(reported)
    suspended = {}
    a = 0
    for x in counter:
        if counter[x] >= k:
            suspended[x] = a
            a += 1
    
    '''
    result = [0] * len(id_list)
    
    for x in range(len(id_list)):
        for y in report:
            if id_list[x] == report[y][0]:
                if report[y][1] in suspended:
                    result[x] += 1
    '''
    
    id_list = {x: i for i, x in enumerate(id_list)}
    
    
    result2 = [0] * len(id_list)
    
    for x in suspended:
        indexs = list(filter(lambda e: reported[e] == x, range(len(reported))))
        for y in indexs:
            result2[id_list[report[y][0]]] += 1
    
    return result2
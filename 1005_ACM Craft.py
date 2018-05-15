# building[i] 는 건물 i를 짓기 위해 필요한 건물 목록

root = []
def makelist(list):
    global building
    global end
    global root
    if list[-1] == end:
        root.append(list)
    else:
        for a in building[list[-1]]:
            makelist(list + [a])

T = int(input())
for i in range(T):
    root = []
    N, K = map(int,input().split())
    time = list(map(int,input().split()))
    building = [[] for j in range(K)]
    for j in range(K):
        temp1, temp2 = map(int,input().split())
        building[temp2-1].append(temp1-1)
    W = int(input()) - 1
    end = building.index([])

    makelist([W])

    min = 0
    for a in root[0]:
        min += time[a]
    for a in root:
        sum = 0
        for b in a:
            sum += time[b]
        if min < sum:
            min = sum
    print(min)
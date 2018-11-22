N, M = map(int, input().split())
DB = {}
for i in range(N+M):
    x = input()
    if x in DB:
        DB[x] += 1
    else:
        DB[x] = 1
answer = []
for x in DB:
    if DB[x] >= 2:
        answer.append(x)
print(len(answer))
for x in sorted(answer):
    print(x)
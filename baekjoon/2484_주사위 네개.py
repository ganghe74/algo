N = int(input())
ans = 0
for _ in range(N):
    x = sorted(map(int, input().split()))
    if x[0] == x[1] == x[2] == x[3]:
        ans = max(ans, 50000 + x[0] * 5000)
    elif x[0] == x[1] == x[2] or x[1] == x[2] == x[3]:
        ans = max(ans, 10000 + x[1] * 1000)
    elif x[0] == x[1] and x[2] == x[3]:
        ans = max(ans, 2000 + x[0] * 500 + x[2] * 500)
    elif x[0] == x[1] or x[1] == x[2]:
        ans = max(ans, 1000 + x[1] * 100)
    elif x[2] == x[3]:
        ans = max(ans, 1000 + x[2] * 100)
    else:
        ans = max(ans, x[3] * 100)
print(ans)
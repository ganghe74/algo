# 거리가
# n제곱일때      1 ~ ~ ~ n ~ ~ ~ 1의 형태를 갖는다
#                 (2n-1) 개
# n제곱 + 1 은   1 ~ ~ ~ n ~ ~ ~ 1 1
#                  2n 개
# n제곱 + n + 1은1 ~ ~ ~ n n ~ ~ ~ 1 1
#                 (2n+1) 개
T = int(input())
for i in range(T):
    x, y = map(int,input().split())
    D = y - x
    n = int(D ** 0.5)
    if D == n**2:
        print(2*n-1)
    elif D <= n**2 + n:
        print(2*n)
    else:
        print(2*n+1)
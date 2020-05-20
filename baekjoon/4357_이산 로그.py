from math import ceil, sqrt

def bsgs(g, h, p):
    N = ceil(sqrt(p - 1))
    tbl = {pow(g, i, p): i for i in range(N)}
    c = pow(g, N * (p - 2), p)
    for j in range(N):
        y = (h * pow(c, j, p)) % p
        if y in tbl:
            return j * N + tbl[y]
    return 'no solution'

while True:
    try:
        p, b, n = map(int, input().split())
        print(bsgs(b, n, p))
    except:
        break


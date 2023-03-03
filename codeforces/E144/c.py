import sys
input=sys.stdin.readline
from collections import defaultdict

MOD = 998244353

t = int(input())
for _ in range(t):
    L, R = map(int, input().split())
    d = defaultdict()

    n = 1
    l = L
    while l * 2 <= R:
        n += 1
        l *= 2

    s = 0
    l = L

    lo = L
    hi = R+1
    while lo + 1 < hi:
        mid = (lo + hi) // 2
        if mid * (2 ** (n-1)) <= R and mid <= R:
            lo = mid
        else:
            hi = mid
    s += lo - L + 1

    lo = L-1
    hi = R+1
    while lo + 1 < hi:
        mid = (lo + hi) // 2
        if mid * (2 ** (n-2)) * 3 <= R and mid <= R:
            lo = mid
        else:
            hi = mid
    s += (lo - L + 1) * (n-1)

    print(n, s)
import sys
input=sys.stdin.readline
from collections import defaultdict

t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    s = input()

    d = defaultdict(int)
    for c in s:
        d[c] += 1

    ans = 0
    for c in 'abcdefghijklmnopqrstuvwxyz':
        C = c.upper()
        mi = min(d[c], d[C])
        d[c] -= mi
        d[C] -= mi
        ans += mi

        rem = max(d[c], d[C])
        if rem > 0 and k > 0:
            x = min(rem // 2, k)
            k -= x
            ans += x

    print(ans)
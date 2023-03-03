import sys
input=sys.stdin.readline
from collections import Counter

def diff(s, t):
    return Counter(s) == Counter(t)

t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    s = input().rstrip()
    t = input().rstrip()

    if n > 2*k:
        print('YES' if diff(s, t) else 'NO')
    elif n <= k:
        print('YES' if s == t else 'NO')
    else:
        ss = s[k:] + s[:n-k]
        tt = t[k:] + t[:n-k]
        f1 = diff(ss, tt)
        f2 = s[n-k:k] == t[n-k:k]
        print('YES' if f1 and f2 else 'NO')
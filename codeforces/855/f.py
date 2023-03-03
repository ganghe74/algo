import sys
input=sys.stdin.readline
from collections import defaultdict

d = [defaultdict(lambda:defaultdict(int)) for _ in range(2)]

ans = 0

n = int(input())
for _ in range(n):
    s = input().rstrip()

    odds = 0
    exst = 0
    for x in s:
        odds ^= 1 << (ord(x) - ord('a'))
        exst |= 1 << (ord(x) - ord('a'))

    for i in range(26):
        if exst & (1 << i):
            continue

        for e, cnt in d[1 - len(s) % 2][(1 << 26) - 1 - (odds ^ (1 << i))].items():
            if (e | exst) == ((1 << 26) - 1 - (1 << i)):
                ans += cnt

    d[len(s) % 2][odds][exst] += 1

print(ans)
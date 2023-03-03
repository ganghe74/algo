import sys
input=sys.stdin.readline
import re

for _ in range(int(input())):
    n = int(input())
    s = input().lower()

    x = re.match('^m+e+o+w+$', s)
    if x:
        print('YES')
    else:
        print('NO')

import sys
input=sys.stdin.readline

i = 0
FB = ''
while i < 30000:
    i += 1
    if i % 3 == 0:
        FB += 'F'
    if i % 5 == 0:
        FB += 'B'

t = int(input())
for _ in range(t):
    k = int(input())
    s = input().strip()
    print('YES' if s in FB else 'NO')

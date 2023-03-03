import sys
input=sys.stdin.readline

def solve(a, b):
    if a[0] == b[0]:
        return a[0] + '*'
    if a[-1] == b[-1]:
        return '*' + a[-1]
    for i in range(len(a)-1):
        if a[i:i+2] in b:
            return '*' + a[i:i+2] + '*'

t = int(input())
for _ in range(t):
    a = input().strip()
    b = input().strip()
    t = solve(a, b)
    if t:
        print('YES')
        print(t)
    else:
        print('NO')
import sys
input=sys.stdin.readline

t = int(input())
for i in range(t):
    n = int(input())
    s = input().rstrip()
    ans = 1
    for i in range(1, n-1):
        if s[i-1] != s[i+1]:
            ans += 1
    print(ans)


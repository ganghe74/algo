def check(s):
    if len(s) <= 1:
        return True
    return s[0] == s[-1] and check(s[1:-1])

T = int(input())
for i in range(T):
    n = input()
    n = str(int(n) + int(n[::-1]))
    print("YES" if check(n) else "NO")
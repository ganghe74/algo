d = {'[':3, '{':2, '(':1, ']':-3, '}':-2, ')':-1}
s = input()
now = 0
ans = 0
for x in s:
    if x in d:
        now += d[x]
    else:
        ans = max(ans, now)
print(ans)
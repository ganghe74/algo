s = input()
ss = set()

for i in range(len(s)):
    s = s[-1] + s[:-1]
    ss.add(s)

print(len(ss))
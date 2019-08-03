def isOne(l):
    a = l[0]
    for x in l:
        if x != a:
            return False
    return True

c = []
n = []
for _ in range(5):
    s = input()
    c.append(s[0])
    n.append(int(s[-1]))

n.sort()
sameColor = isOne(c)
same4 = isOne(n[:-1]) or isOne(n[1:])
same3 = isOne(n[:-2]) or isOne(n[1:-1]) or isOne(n[2:])
same2 = isOne(n[:-3]) or isOne(n[1:-2]) or isOne(n[2:-1]) or isOne(n[3:])
continuous = n[0]+4 == n[1]+3 == n[2]+2 == n[3]+1 == n[4]

if same4:
    n4 = n[1]
if same3:
    n3 = n[2]
if same2:
    if isOne(n[:-3]) or isOne(n[1:-2]):
        n2 = n[1]
    else:
        n2 = n[3]

ans = 0
if sameColor and continuous:
    ans = max(ans, max(n)+900)

if same4:
    ans = max(ans, n4+800)

if same3 and n[0] == n[1] and n[3] == n[4]:
    if isOne(n[2:]):
        ans = max(ans, n[2] * 10 + n[0] + 700)
    else:
        ans = max(ans, n[2] * 10 + n[3] + 700)

if sameColor:
    ans = max(ans, max(n)+600)

if continuous:
    ans = max(ans, max(n)+500)

if same3:
    ans = max(ans, n3+400)

if same2:
    if n[0] == n[1] and n[2] == n[3]:
        ans = max(ans, n[2] * 10 + n[0] + 300)
    if n[0] == n[1] and n[3] == n[4]:
        ans = max(ans, n[3] * 10 + n[0] + 300)
    if n[1] == n[2] and n[3] == n[4]:
        ans = max(ans, n[3] * 10 + n[1] + 300)
    ans = max(ans, n2+200)

ans = max(ans, max(n)+100)

print(ans)
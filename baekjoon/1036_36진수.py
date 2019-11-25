numc = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ'
N = int(input())
strs = []
for i in range(N):
    strs.append(input())
K = int(input())

def getCost(x):
    cost = 0
    for s in strs[::-1]:
        cost += (int(s.replace(x, 'Z'), 36) - int(s, 36))
    return cost
        

for k in range(K): # 50
    maxCost = -1
    maxChar = ''
    for x in numc:
        cost = getCost(x)
        if cost > maxCost:
            maxCost = cost
            maxChar = x
    for i in range(len(strs)):
        strs[i] = strs[i].replace(maxChar, 'Z')

def convert(n):
    if n == 0:
        return ''
    return convert(n // 36) + numc[n % 36]

s = sum([int(s, 36) for s in strs])
print(0) if s == 0 else print(convert(s))
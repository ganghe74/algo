N = int(input())

lines = ['*']

def f():
    space = (len(lines[0]) + 3) // 2
    for i in range(len(lines)):
        s = ' ' * (i+1) + '*' + ' ' * (space-i-2)
        lines[i] = s + lines[i] + s[::-1]
    l = len(lines[0])
    lines.insert(0, '*' * l)
    for i in range(space, l//2):
        s = ' ' * i + '*' + ' ' * (l//2-i-1)
        lines.append(s + ' ' + s[::-1])
    lines.append(' ' * (l // 2) + '*' + ' ' * (l // 2))

for i in range(N-1):
    f()
    lines.reverse()

if N % 2 == 0:
    lines.reverse()

for s in lines:
    print(s.rstrip())

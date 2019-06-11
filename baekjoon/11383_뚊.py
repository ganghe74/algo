N, M = map(int, input().split())
a = []
b = []
for i in range(N):
    a.append(input())
for i in range(N):
    b.append(input())
eyfa = True
for i in range(N):
    if ''.join([x*2 for x in a[i]]) != b[i]:
        eyfa = False
print('Eyfa' if eyfa else 'Not Eyfa')
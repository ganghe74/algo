n = int(input())
for i in range(n):
    loc, animals = input().split()
    x = []
    x.append((animals.count('B')*2, 'Bobcat'))
    x.append((animals.count('C'), 'Coyote'))
    x.append((animals.count('M')*4, 'Mountain Lion'))
    x.append((animals.count('W')*3, 'Wolf'))
    x.sort()
    if x[3][0] == x[2][0]:
        print('%s: There is no dominant species'%loc)
    else:
        print('%s: The %s is the dominant species'%(loc, x[3][1]))
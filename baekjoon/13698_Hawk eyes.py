a = [1, 0, 0, 2]
for x in input():
    if x == 'A':
        a[0], a[1] = a[1], a[0]
    elif x == 'B':
        a[0], a[2] = a[2], a[0]
    elif x == 'C':
        a[0], a[3] = a[3], a[0]
    elif x == 'D':
        a[1], a[2] = a[2], a[1]
    elif x == 'E':
        a[1], a[3] = a[3], a[1]
    else:
        a[2], a[3] = a[3], a[2]
print(a.index(1)+1, a.index(2)+1)
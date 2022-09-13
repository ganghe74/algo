t = int(input())
for _ in range(t):
    x1, y1, r1, x2, y2, r2 = map(int, input().split())
    d = ((x1-y1)**2 + (x2-y2)**2) ** 0.5
    if r1 < r2:
        x1, y1, r1, x2, y2, r2 = x2, y2, r2, x1, y1, r1
    d = (x1-x2)**2+(y1-y2)**2

    if x1 == x2 and y1 == y2:
        print(-1 if r1==r2 else 0)
    elif d < r1**2:
        r = (r1-r2)**2
        if d > r:
            print(2)
        elif d == r:
            print(1)
        else:
            print(0)
    else:
        r = (r1+r2)**2
        if d > r:
            print(0)
        elif d == r:
            print(1)
        else:
            print(2)

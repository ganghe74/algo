a, b, c = map(int,input().split())
acbd = (a*a - b*b) * (a*a - c*c)
x = (acbd ** 0.5 - b*c) / a
if x > 0:
    print(int(x))
else:
    print(-1)
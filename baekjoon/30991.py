n=int(input())
def f(a,b,c):
    return a-c, b+c, 2*a-2*b+c
a, b, c = 0, 0, 1
for _ in range(n):
    a, b, c = f(a,b,c)
print(a+b+c)
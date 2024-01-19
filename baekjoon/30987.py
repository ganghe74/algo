x1, x2 = map(int,input().split())
a, b, c, d, e = map(int,input().split())
def h(x):
    return x**3*a//3 + x**2*(b-d)//2 + x*(c-e)
print(h(x2)-h(x1))
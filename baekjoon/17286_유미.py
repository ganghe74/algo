me = tuple(map(int,input().split()))
A = tuple(map(int,input().split()))
B = tuple(map(int,input().split()))
C = tuple(map(int,input().split()))
f = lambda a, b : ((a[0]-b[0])**2 + (a[1]-b[1])**2) ** 0.5
ff = lambda a, b, c, d : f(a,b) + f(b,c) + f(c,d)
ans = min(ff(me,A,B,C), ff(me,A,C,B), ff(me,B,A,C), ff(me,B,C,A), ff(me,C,A,B), ff(me,C,B,A))
print(int(ans))
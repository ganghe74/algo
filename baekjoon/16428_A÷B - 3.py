A, B = map(int, input().split())
q = A//B
r = A%B
if r<0:
    r-=B
    q+=1
print("%d\n%d"%(q, r))
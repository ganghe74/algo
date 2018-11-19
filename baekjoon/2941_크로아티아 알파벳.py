A = ['c=','c-','dz=','d-','lj','nj','s=','z=']
W = input()
L = len(W)
for i in A:
    L -= W.count(i)
print(L)
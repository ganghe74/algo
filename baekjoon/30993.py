N,A,B,C=map(int,input().split())
def binom(n,k):
    if k==0 or k==n:
        return 1
    else:
        return binom(n-1,k-1)+binom(n-1,k)
x = binom(N,A) * binom(N-A,B) * binom(N-A-B,C)
print(x)
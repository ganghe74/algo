from itertools import combinations
from fractions import Fraction
N,M,K=map(int,input().split())
P = [0] * (N+1)
for _ in range(M-1):
    a,b,c = map(int,input().split())
    P[a] += 1
    P[b] += 1
    P[c] += 1
def f(a,b,c):
    pa = Fraction(P[a]+1, sum(P)+3)
    pb = Fraction(P[b]+1, sum(P)+3)
    pc = Fraction(P[c]+1, sum(P)+3)
    return (1-pa-pb-pc) ** K * (pa+pb+pc)
mp = 0
for a,b,c in combinations(range(1,N+1),3):
    p = f(a,b,c)
    if p > mp:
        mp = p
        m = a,b,c
print(mp.numerator, mp.denominator)
print(*m)
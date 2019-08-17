from decimal import *
getcontext().prec = 1000
T = int(input())
for _ in range(T):
    s = str(round(Decimal(input()) ** (Decimal(1) / Decimal(3)), 500))
    print(s[:s.index('.')+11])
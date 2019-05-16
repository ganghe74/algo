from decimal import *
getcontext().prec = 1500
a, b = map(Decimal, input().split())
print(format(a ** b, 'f'))
from decimal import *
getcontext().prec = 1500
a, b = map(Decimal, input().split())
c = 299792458
print(format((a+b) / (1+(a*b)/(c*c)), 'f'))
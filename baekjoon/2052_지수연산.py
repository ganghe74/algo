from decimal import *
getcontext().prec = 300
print(format(Decimal(2) ** -int(input()), 'f'))
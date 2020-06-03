from decimal import *
getcontext().prec = 100
p = Decimal('3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117068') * 2
A, B, C = map(Decimal, input().split())

def sin(x):
    x %= p
    getcontext().prec += 2
    i, lasts, s, fact, num, sign = 1, 0, x, 1, x, 1
    while s != lasts:
        lasts = s
        i += 2
        fact *= i * (i-1)
        num *= x * x
        sign *= -1
        s += num / fact * sign
    getcontext().prec -= 2
    return +s

def f(x):
    return A*x + B*sin(x) - C

x = Decimal('500000')
dx = Decimal('500000')

if f(x) < 0:
    x = -x

while f(x) > Decimal('1e-20') and dx > Decimal('0'):
    if 0 <= f(x+dx) < f(x):
        x += dx
    elif 0 <= f(x-dx) < f(x):
        x -= dx
    dx /= 2

print(x.quantize(Decimal('0.000001'), rounding=ROUND_HALF_UP))

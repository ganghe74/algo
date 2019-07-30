from math import gcd
lcm = lambda x, y : x * y // gcd(x, y)
s = input()
t = input()
l = lcm(len(s), len(t))
if s * (l // len(s)) == t * (l // len(t)):
    print(1)
else:
    print(0)
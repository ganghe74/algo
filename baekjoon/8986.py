n = int(input())
L = [int(x) for x in input().split()]

def f(stride):
  return sum(abs(x - stride * i) for i, x in enumerate(L))

lo = 1
hi = int(2e9)
while lo + 2 < hi:
  # print(lo, hi)
  p = (lo * 2 + hi) // 3
  q = (lo + hi * 2) // 3
  if f(p) > f(q):
    lo = p
  else:
    hi = q

while f(lo+1) < f(lo): lo += 1
while f(lo-1) < f(lo): lo -= 1
print(f(lo))
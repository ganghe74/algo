from math import log
def big_star(x):
    c = len(x)
    for i in range(c):
        star.append(x[i] + x[i])
        x[i] = "   " * (c // 3) + x[i] + "   " * (c // 3)
    return x
star = ["  *   ", " * *  ", "***** "]
N = int(input())
N = N // 3
N = int(log(N,2))
for i in range(N):
    star = big_star(star)
for i in star:
    print(i)
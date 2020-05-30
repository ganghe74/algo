from math import cos, pi

for _ in range(int(input())):
    n = int(input())
    n *= 2
    ans = 0.0

    theta = angle = 180 - 180 * (n-2) / (n)
    while theta < 90:
        ans += cos(theta * pi / 180)
        theta += angle
    ans = ans * 2 + 1
    print(ans)

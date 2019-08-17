for _ in range(int(input())):
    p = list(map(int, input().split()))
    score = 0
    score += int(9.23076 * ((26.7 - p[0]) ** 1.835))
    score += int(1.84523 * ((p[1] - 75) ** 1.348))
    score += int(56.0211 * ((p[2] - 1.5) ** 1.05))
    score += int(4.99087 * ((42.5 - p[3]) ** 1.81))
    score += int(0.188807 * ((p[4] - 210) ** 1.41))
    score += int(15.9803 * ((p[5] - 3.8) ** 1.04))
    score += int(0.11193 * ((254 - p[6]) ** 1.88))
    print(score)
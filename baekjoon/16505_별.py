N = int(input())
STAR = ["*"]
for i in range(N):
    for j in range(len(STAR)):
        STAR.append(STAR[j] + " " * len(STAR[0]))
    for j in range(len(STAR)//2):
        STAR[j] += STAR[j]
for x in STAR:
    print(x.rstrip())
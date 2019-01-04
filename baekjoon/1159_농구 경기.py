last = {}
for x in "abcdefghijklmnopqrstuvwxyz":
    last[x] = 0
N = int(input())
for i in range(N):
    last[input()[0]] += 1
answer = ""
for key in last:
    if last[key] >= 5:
        answer += key
if answer == "":
    print("PREDAJA")
else:
    print(answer)
s = input()
before = -1
cnt = 0
ans = 0
for x in s:
    if before + 1 == ord(x):
        cnt += 1
    else:
        cnt = 0
    if cnt == 2:
        ans += 1
    if cnt == 3:
        ans -= 1
    before = ord(x)
print(ans)
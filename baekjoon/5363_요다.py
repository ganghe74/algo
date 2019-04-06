N = int(input())
for i in range(N):
    ss = input().split()
    print(" ".join(ss[2:] + ss[:2]))
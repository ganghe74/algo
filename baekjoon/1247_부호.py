import sys
for T in range(3):
    N = int(sys.stdin.readline())
    S = 0
    for i in range(N):
        S += int(sys.stdin.readline())
    if S == 0:
        print(0)
    elif S > 0:
        print('+')
    else:
        print('-')
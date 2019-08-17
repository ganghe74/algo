for _ in range(int(input())):
    N = input()
    if str(int(N)**2)[-len(N):] == N:
        print("YES")
    else:
        print("NO")
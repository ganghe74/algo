while True:
    B, N = map(int, input().split())
    if B == 0 and N == 0:
        break
    x = int(B ** (1/N))
    if B - x**N < (x+1)**N - B:
        print(x)
    else:
        print(x+1)
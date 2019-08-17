for _ in range(int(input())):
    n = int(input())
    ans = 1
    for i in range(1, n+1):
        ans *= i
        while ans % 10 == 0:
            ans //= 10
        ans %= 1000000000
    print(str(ans).rstrip('0')[-1])
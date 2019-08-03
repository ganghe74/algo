T = int(input())
for i in range(1, T+1):
    a, b, c = sorted(map(int,input().split()))
    print('Scenario #%d:'%i)
    print('yes\n' if a*a+b*b==c*c else 'no\n')
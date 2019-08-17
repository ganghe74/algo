T = int(input())
for i in range(T):
    x = input().split()
    n = float(x[0])
    for op in x[1:]:
        if op == '@':
            n *= 3
        elif op == '%':
            n += 5
        elif op == '#':
            n -= 7
    print('%.2f'%n)
tc = 0
while True:
    tc += 1
    a, b, c = map(int, input().split())
    if a == b == c == 0:
        break
    if a == -1:
        n = c*c - b*b
        x = 'a'
    elif b == -1:
        n = c*c - a*a
        x = 'b'
    else:
        n = a*a + b*b
        x = 'c'
    print('Triangle #%d'%tc)
    if n <= 0:
        print('Impossible.')
    else:
        print('%c = %.3f'%(x, n**0.5))
    print()
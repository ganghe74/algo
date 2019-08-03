T = int(input())
for _ in range(T):
    a, b, c, d, e = map(int, input().split())
    print('$%.2f'%(350.34 * a + 230.90 * b + 190.55 * c + 125.30 * d + 180.90 * e))
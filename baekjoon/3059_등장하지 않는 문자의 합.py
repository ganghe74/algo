T = int(input())
for _ in range(T):
    print(sum(ord(x) for x in set('ABCDEFGHIJKLMNOPQRSTUVWXYZ') - set(input())))
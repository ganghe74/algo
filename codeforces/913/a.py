t = int(input())
for _ in range(t):
    p = input()
    for c in 'abcdefgh':
        if p[0] != c:
            print(c + p[1])
    for i in '12345678':
        if p[1] != i:
            print(p[0] + i)
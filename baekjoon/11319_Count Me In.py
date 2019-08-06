T = int(input())
for _ in range(T):
    c, v = 0, 0
    s = input()
    for x in s.lower():
        if x.isalpha():
            if x in 'aeiou':
                v += 1
            else:
                c += 1
    print(c, v)
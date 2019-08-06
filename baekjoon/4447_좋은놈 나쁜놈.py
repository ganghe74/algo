T = int(input())
for _ in range(T):
    s = input()
    g = s.lower().count('g')
    b = s.lower().count('b')
    if g == b:
        print(s, 'is NEUTRAL')
    elif g > b:
        print(s, 'is GOOD')
    else:
        print(s, 'is A BADDY')
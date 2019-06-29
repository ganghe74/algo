def go(x, key):
    for k in key:
        x = chr((ord(k) + ord(x) - ord('A')) % 26 + ord('A'))
    return x

a = 'C'
s = input()

for x in s:
    print(go(x, a+'HICKENS'), end='')
    a = chr((ord(a) - ord('A') + 1) % 26 + ord('A'))
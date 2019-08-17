n, k = map(int, input().split())
s = ''.join([bin(i)[2:] for i in range(100)])
for i in range(5):
    print(s[k-1+n*i], end=' ')
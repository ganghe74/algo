X, Y = input().split()
print(str(int(X[::-1]) + int(Y[::-1]))[::-1].lstrip('0'))
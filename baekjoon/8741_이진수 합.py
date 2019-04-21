k = int(input())
k = 1 << k
print(bin(k * (k-1) // 2)[2:])
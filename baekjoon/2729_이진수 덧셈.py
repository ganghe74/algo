T = int(input())
for i in range(T):
    a, b = input().split()
    print(bin(int(a, 2)+int(b, 2))[2:])
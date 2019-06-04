A, B = map(int, input().split())
print(A // B, end=".")
for i in range(1900):
    A %= B
    A *= 10
    print(A // B, end="")
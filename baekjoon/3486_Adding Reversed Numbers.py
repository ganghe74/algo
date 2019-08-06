N = int(input())
for _ in range(N):
    A, B = input().split()
    print(int(str(int(A[::-1]) + int(B[::-1]))[::-1]))
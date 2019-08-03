A, B, C, D = map(int, input().split())
print(max(min(A,B)*min(C,D), min(A,C)*min(B,D), min(A,D)*min(B,C)))
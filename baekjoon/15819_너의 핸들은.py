N, I = map(int, input().split())
handles = sorted([input() for i in range(N)])
print(handles[I-1])
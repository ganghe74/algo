# Time Limit Code! ! !

n = int(input())
a = [int(x) for x in input().split()]
answer = []
for i in range(n):
    b = a[:i] + a[i+1:]
    if (max(b) == sum(b) - max(b)):
        answer.append(i+1)
print(len(answer))
for x in answer:
    print(x, end=" ")
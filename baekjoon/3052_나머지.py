x = []
for i in range(10):
    x.append(int(input())%42)
print(len(set(x)))
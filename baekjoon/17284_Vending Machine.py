d = {1:500, 2:800, 3:1000}
s = map(int, input().split())
s = [d[x] for x in s]
print(5000-sum(s))
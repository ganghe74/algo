class bug:
    def __init__(self, year):
        self.x = 3
        if year % 2 == 0:
            self.x = 4
    def ang(self):
        self.x -= 1
        return self.x >= 0

bugs = [bug(1)]
N = int(input())
for i in range(2, N+1):
    next = []
    for b in bugs:
        if b.ang():
            next.append(bug(i))
        if b.x > 0:
            next.append(b)
    bugs = next
print(len(bugs))
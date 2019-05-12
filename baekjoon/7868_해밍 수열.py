LIMIT = 1000000000000000000
p1, p2, p3, i = map(int, input().split())

nums = []
i1 = i2 = i3 = 0
while p1**i1 < LIMIT:
    while p1**i1 * p2**i2 < LIMIT:
        while p1**i1 * p2**i2 * p3**i3 < LIMIT:
            nums.append(p1**i1 * p2**i2 * p3**i3)
            i3 += 1
        i3 = 0
        i2 += 1
    i2 = 0
    i1 += 1

nums.sort()
print(nums[i])
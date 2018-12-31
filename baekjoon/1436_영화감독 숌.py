N = int(input())
nums = []
x = 666
while len(nums) < N:
    if str(x).count('666') > 0:
        nums.append(x)
    x += 1
print(nums[-1])
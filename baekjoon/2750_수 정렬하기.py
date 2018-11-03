# 킹갓내장함수
N = int(input())
nums = []
for i in range(N):
    nums.append(int(input()))
nums.sort()
for i in nums:
    print(i)

# 버블정렬 ?
N = int(input())
nums = []
for i in range(N):
    nums.append(int(input()))
for i in range(N):
    for j in range(i+1,N):
        if nums[i] > nums[j]:
            nums[i], nums[j] = nums[j], nums[i]
for i in nums:
    print(i)
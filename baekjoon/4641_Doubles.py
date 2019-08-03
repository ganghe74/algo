while True:
    nums = list(map(int, input().split()))[:-1]
    if len(nums) == 0:
        break
    cnt = 0
    for x in nums:
        if x * 2 in nums:
            cnt += 1
    print(cnt)
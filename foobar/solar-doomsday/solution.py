def solution(area):
    ans = []
    i = 1000
    while area > 0:
        while area >= i*i:
            area -= i*i
            ans.append(i*i)
        i -= 1
    return ans

# 입력
n, c = map(int, input().split())
L = sorted([int(input()) for _ in range(n)])

# 조건 함수 정의
def g(x):
  px = L[0] # 이전에 설치된 공유기의 위치
  cnt = 1   # 설치한 공유기의 개수
  i = 1     # 현재 고려하고 있는 집의 인덱스

  while i < n:
    if L[i] - px >= x:
      px = L[i]
      cnt += 1
    i += 1

  return cnt >= c


# 초깃값 설정
lo = 0          # g(lo) == True
hi = int(1e9+5) # g(hi) == False

# 이진 탐색
while lo + 1 < hi:
  mid = (lo + hi) // 2
  if g(mid):
    lo = mid
  else:
    hi = mid

# 출력
print(lo)
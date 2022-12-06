MOD = 1000000000

# DP Table with shape: n x 10 x (2^10)
d = [
  [[-1] * (2 ** 10) for _ in range(10)]
  for _ in range(105)
]


def count_step_num(len, digit, state):
  # 기저조건
  if len == 1:
    if digit == 0:
      return 0
    if state == 0b1111111111:
      return 1
    return 0

  # DP Table 확인
  if d[len][digit][state] != -1:
    return d[len][digit][state]

  # DP 테이블을 점화식에 의해 채움
  ret = 0
  if digit > 0:
    nstate = state | (1 << (digit-1))
    ret += count_step_num(len-1, digit-1, nstate)
  if digit < 9:
    nstate = state | (1 << (digit+1))
    ret += count_step_num(len-1, digit+1, nstate)
  ret %= MOD

  # 리턴
  d[len][digit][state] = ret
  return ret


n = int(input())

ans = 0
for i in range(10):
  ans += count_step_num(n, i, 1<<i)
  ans %= MOD

print(ans)

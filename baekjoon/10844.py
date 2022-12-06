MOD = 1000000000

# DP Table with shape n x 10
d = [[-1] * 10 for _ in range(105)]


def count_step_num(len, digit):
  # 기저조건
  if len == 1:
    return 1 if digit != 0 else 0

  # DP Table 확인
    # int &x = y; 형식의 문법이 안되는게 불편했음
  if d[len][digit] != -1:
    return d[len][digit]

  # DP 테이블을 점화식에 의해 채움
  ret = 0
  if digit > 0:
    ret += count_step_num(len-1, digit-1)
  if digit < 9:
    ret += count_step_num(len-1, digit+1)
  ret %= MOD

  # 리턴
  d[len][digit] = ret
  return ret


n = int(input())

ans = 0
for i in range(10):
  ans += count_step_num(n, i)
  ans %= MOD

print(ans)
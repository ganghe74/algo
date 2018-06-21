# 처음 짠 코드 (런타임에러)
for i in range(100):
    print(input())

# 구글에서 찾은 코드
import sys
for line in sys.stdin:
    print(line, end="")

# 예외처리법
while True:
    try:
        print(input())
    except EOFError:
        break

# sys.stdin.readline()
import sys
for i in range(100):
    print(sys.stdin.readline(), end="")

# sys.stdin.read()
import sys
print(sys.stdin.read())
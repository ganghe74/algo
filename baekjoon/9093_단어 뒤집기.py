T = int(input())
for i in range(T):
    line = input()
    for word in line.split():
        print(word[::-1], end = " ")
    print()
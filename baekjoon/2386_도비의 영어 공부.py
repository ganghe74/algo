while True:
    x = input().split()
    if x[0] == '#':
        break
    cnt = 0
    for word in x[1:]:
        cnt += word.lower().count(x[0])
    print(x[0], cnt)
while True:
    a, b = input().split()
    if a == b == '0':
        break
    c = str(int(a) + int(b))
    a = a.zfill(len(c))
    b = b.zfill(len(c))
    cnt = 0
    for i in range(len(c)):
        if (int(a[i]) + int(b[i])) % 10 != int(c[i]):
            cnt += 1
    print(cnt)

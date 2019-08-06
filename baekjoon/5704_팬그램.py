while True:
    s = input()
    if s == '*':
        break
    if len(set('abcdefghijklmnopqrstuvwxyz') - set(s)) == 0:
        print('Y')
    else:
        print('N')
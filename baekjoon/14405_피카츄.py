s = input()
while len(s) > 0:
    if s[:2] == 'pi' or s[:2] == 'ka':
        s = s[2:]
    elif s[:3] == 'chu':
        s = s[3:]
    else:
        break
print('YES' if s == '' else 'NO')
def f(x):
    if x == ' ':
        return -1
    elif x in 'aeiou':
        return 0
    else:
        return 1

def hasMo(s):
    for x in s:
        if f(x) == 0:
            return True
    return False

def check(s):
    if not hasMo(s):
        return False
    s = '  ' + s
    for i in range(2, len(s)):
        if s[i-1] == s[i] and s[i] not in 'eo':
            return False
        if f(s[i-2]) == f(s[i-1]) == f(s[i]):
            return False
    return True

while True:
    s = input()
    if s == 'end':
        break
    print('<{}> is {}acceptable.'.format(s, '' if check(s) else 'not '))
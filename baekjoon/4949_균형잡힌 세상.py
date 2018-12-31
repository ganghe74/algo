def check(s):
    gwalho = ''
    for x in s:
        if x in ['(', ')', '[', ']']:
            gwalho += x
    print(gwalho)
    stack = ''
    for x in gwalho:
        if x in ['(', '[']:
            stack += x
        elif x == ')':
            if stack[-1:] == '(':
                stack = stack[:-1]
            else:
                return False
        else:
            if stack[-1:] == '[':
                stack = stack[:-1]
            else:
                return False
    if len(stack) != 0:
        return False
    return True

s = ''
while s != '.':
    s = ''
    while s[-1:] != '.':
        s += input()
    if s == '.':
        break
    else:
        if check(s):
            print("yes")
        else:
            print("no")
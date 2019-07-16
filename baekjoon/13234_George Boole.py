s = input().replace('true', 'True').replace('false', 'False').replace('AND', '&').replace('OR', '|')
print(str(eval(s)).lower())
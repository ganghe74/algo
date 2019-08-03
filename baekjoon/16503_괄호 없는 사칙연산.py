x = input().split()
x = [int(eval(str(int(eval(x[0]+x[1]+x[2])))+x[3]+x[4])), int(eval(x[0]+x[1]+str(int(eval(x[2]+x[3]+x[4])))))]
print(min(x))
print(max(x))
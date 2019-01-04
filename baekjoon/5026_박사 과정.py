N = int(input())
for i in range(N):
    s = input()
    if s == "P=NP":
        print("skipped")
    else:
        print(eval(s))
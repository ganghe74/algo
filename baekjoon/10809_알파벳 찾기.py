x = input()

for i in range(97,123):
    locate = -1
    for j in range(len(x)):
        if chr(i) == x[j]:
            locate = j
            break
    print(locate, end=" ")

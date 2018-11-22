words = []
N = int(input())
for i in range(N):
    words.append(input())
for i in range(N-1):
    for j in range(i,N):
        if words[i] == words[j][::-1]:
            print(len(words[i]), words[i][len(words[i])//2])
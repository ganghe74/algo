N, word = input().split()
words = []
if N == '1' or N == '3':
    word = word[0].upper() + word[1:]
    word += 'A'
    preIndex = 0
    for i in range(1, len(word)):
        if word[i].isupper():
            words.append(word[preIndex:i])
            preIndex = i
elif N == '2':
    words = word.split('_')
    for i in range(len(words)):
        words[i] = words[i][0].upper() + words[i][1:]

print(words[0].lower(), end="")
for x in words[1:]:
    print(x ,end = "")
print()
for x in words[:-1]:
    print(x.lower(), end ="_")
print(words[-1].lower())
for x in words:
    print(x, end="")
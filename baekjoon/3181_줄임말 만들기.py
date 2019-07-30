filters = ['i', 'pa', 'te', 'ni', 'niti', 'a', 'ali', 'nego', 'no', 'ili']
words = input().split()
ans = words[0][0].upper()
for word in words[1:]:
    if word in filters:
        continue
    ans += word[0].upper()
print(ans)
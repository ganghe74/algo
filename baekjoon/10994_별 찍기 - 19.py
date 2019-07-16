def f(star):
    l = len(star) + 2
    star = [' ' * l] + [' ' + line + ' ' for line in star] + [' ' * l]
    l += 2
    star = ['*' * l] + ['*' + line + '*' for line in star] + ['*' * l]
    return star

ans = ['*']
N = int(input())
for i in range(1, N):
    ans = f(ans)

print('\n'.join(ans))
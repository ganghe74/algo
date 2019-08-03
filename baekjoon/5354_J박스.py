T = int(input())
for i in range(T):
    n = int(input())
    for j in range(n):
        if j == 0 or j == n-1:
            print('#' * n)
        else:
            print('#' + 'J' * (n-2) + '#')
    print()
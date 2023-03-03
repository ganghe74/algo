for T in (100, 1000, 10000):
    with open(f'big-{T}.in', 'w') as f:
        f.write(f'{T}\n')
        for _ in range(T):
            f.write('a' * 50 + '\n')
            f.write('b' * 50 + '\n')

    with open(f'big-{T}.ans', 'w') as f:
        for _ in range(T):
            f.write('NO\n')
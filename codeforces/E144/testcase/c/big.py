for T in (1000, 10000, 20000):
    with open(f'big-{T}.in', 'w') as f:
        f.write(f'{T}\n')
        for _ in range(T):
            f.write('1 1000000\n')
from random import shuffle

print('it may take about 20 seconds...')
print('please wait.')

inputs = [i for i in range(1, 10000001)]
shuffle(inputs)

with open('input.txt', 'w') as f:
    f.write(f'{len(inputs)}\n')
    f.write('\n'.join(map(str, inputs)))
    f.write('\n')

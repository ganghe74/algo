def f(card):
    ret = 0
    x = abs(int(card[0],16) - int(card[2],16))
    ret += 10000000 * (x == 1 or x == 14)
    ret += 1000000 * (x == 0)
    ret += 100000 * (card[1] == card[3])
    ret += 1000 * (int(max(card[0], card[2]), 16))
    ret += 10 * (int(min(card[0], card[2]), 16))
    ret += card[1] == 'b' if card[0] > card[2] else card[3] == 'b'
    return ret

cards = input().split(',')
pair = []
for i in range(len(cards)):
    for j in range(i+1, len(cards)):
        pair.append(cards[i] + cards[j])

pair = sorted(pair, key=f, reverse=True)
print('\n'.join(pair))
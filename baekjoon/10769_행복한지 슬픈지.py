s = input()
happy = s.count(':-)')
sad = s.count(':-(')
if happy == sad == 0:
    print('none')
elif happy > sad:
    print('happy')
elif sad > happy:
    print('sad')
else:
    print('unsure')
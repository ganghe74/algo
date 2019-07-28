try:
    while True:
        s = input()
        while s.find('BUG') != -1:
            s = s.replace('BUG', '')
        print(s)
except:
    pass
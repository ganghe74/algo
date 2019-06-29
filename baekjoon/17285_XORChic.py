def strxor(s, key):
    return "".join([chr(ord(x)^key) for x in s])

s = input()
for i in range(128):
    if strxor(s[:8], i) == "CHICKENS":
        print(strxor(s, i))
        break
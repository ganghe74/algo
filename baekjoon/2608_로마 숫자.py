romans = [
    (1000, "M"), (900, "CM"), (500, "D"), (400, "CD"),
    (100, "C"), (90, "XC"), (50, "L"), (40, "XL"),
    (10, "X"), (9, "IX"), (5, "V"), (4, "IV"),
    (1, "I")
]

def decToRoman(n):
    result = ""
    for value, letters in romans:
        while n >= value:
            result += letters
            n -= value
    return result

def romanToDec(numstr):
    result = 0
    for value, letters in romans:
        while numstr[:len(letters)] == letters:
            numstr = numstr[len(letters):]
            result += value
    return result

answer = romanToDec(input())
answer += romanToDec(input())
print(answer)
print(decToRoman(answer))
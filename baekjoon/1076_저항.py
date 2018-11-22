db = {
    "black":0, "brown":1, "red":2, "orange":3, "yellow":4,
    "green":5, "blue":6, "violet":7, "grey":8, "white":9
}
answer = db[input()] * 10
answer += db[input()]
answer *= 10**db[input()]
print(answer)
dic = {"AA":"A", "AG":"C", "AC":"A", "AT":"G",
    "GA":"C", "GG":"G", "GC":"T", "GT":"A",
    "CA":"A", "CG":"T", "CC":"C", "CT":"G",
    "TA":"G", "TG":"A", "TC":"G", "TT":"T"
}
s = input()
s = input()
while len(s) > 1:
    s = s[:-2] + dic[s[-2:]]
print(s)
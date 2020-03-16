import zlib

lines = []

with open('genzaw/last4', 'r') as f:
    for i in range(4):
        f.readline()
        f.readline()
        f.readline()
        s1 = f.readline()
        s2 = f.readline()
        f.readline()

        line = ''
        while True:
            if s1[:2] == '##' and s2[:2] == '##':
                line += '0'
                s1 = s1[7:]
                s2 = s2[7:]
            elif s1[:2] == '.#' and s2[:2] == '.#':
                line += '1'
                s1 = s1[4:]
                s2 = s2[4:]
            elif s1[:2] == '..' and s2[:2] == '.#':
                line += '2'
                s1 = s1[7:]
                s2 = s2[7:]
            elif s1[:2] == '.#' and s2[:2] == '..':
                line += '3'
                s1 = s1[7:]
                s2 = s2[7:]
            else:
                break
        lines.append(line)

for line in lines:
    print(line)


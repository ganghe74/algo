import zlib, base64

with open('genzaw/gen10.out', 'r') as f:
    lines = f.readlines()
    s = ''.join(lines)
    s = s[:-1]
    c = zlib.compress(s.encode('utf-8'))
    cb85 = base64.b85encode(c)

    print(len(s))
    print(len(str(c)))
    print(len(str(cb85)))
    print(str(cb85))

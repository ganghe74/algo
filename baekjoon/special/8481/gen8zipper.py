import zlib, base64

# 0 is north, clockwise

dr = [-1,-1,0,1,1,1,0,-1]
dc = [0,1,1,1,0,-1,-1,-1]

data = 0
data_s = ''
a = None

with open('genzaw/gen8.out', 'r') as f:
    lines = f.readlines()
    a = [list(line.rstrip()) for line in lines]
    print(lines[717][48])
    print(lines[500][500])
    print(lines[500 + dr[3]][500 + dc[3]])
    r = 717
    c = 48
    while True:
        a[r][c] = '.'
        for k in range(8):
            nr = r + dr[k]
            nc = c + dc[k]
            if a[nr][nc] == '#':
                data = data * 8 + (k + 4) % 8
                data_s = str((k+4)%8) + data_s
                r = nr
                c = nc
                break
        if a[r][c] == '#':
            continue
        break
    #  print(r, c)
    #  print(data % 8)
    #  byte = data.to_bytes(data.bit_length(), byteorder='little')
    #  data_s = str(data)
    byte = data_s.encode('utf-8')
    compressed = zlib.compress(byte)
    compressed_b85 = base64.b85encode(compressed)
    print('byte', len(str(byte)))
    print('compressed', len(str(compressed)))
    print('compressed, base85', len(str(compressed_b85)))

    #  decompressed = int.from_bytes(zlib.decompress(base64.b85decode(compressed_b85)), byteorder='little')
    decompressed = zlib.decompress(base64.b85decode(compressed_b85)).decode('utf-8')
    print('data == decompressed', data_s == decompressed)

    #  print(compressed_b85)
    print(decompressed)

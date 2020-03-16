import zlib, base64
import sys

sys.setrecursionlimit(2000)

# 0 is east, clockwise

dr = [0,1,1,1]
dc = [1,1,0,-1]

visited = [[False] * 1003 for _ in range(1003)]

def dfs(r, c, k):
    visited[r][c] = True
    nr = r + dr[k]
    nc = c + dc[k]
    if 0 <= nr < 1003 and 0 <= nc < 1003:
        if a[nr][nc] == '#':
            return dfs(nr, nc, k) + 1
    return 1
    

with open('genzaw/gen9.out', 'r') as f:
    lines = f.readlines()
    a = [list(line.rstrip()) for line in lines]

    dat = 0
    cnt = 0

    for r in range(1003):
        for c in range(1003):
            if not visited[r][c] and a[r][c] == '#':
                for i in range(4):
                    l = dfs(r, c, i)
                    if l > 1:
                        info = r * (2**23) + c * (2**13) + l*(2**2) + i
                        dat = dat * (2**33) + info
                        cnt += 1
                        break

    #  for r in range(1003):
        #  for c in range(1003):
            #  if not visited[r][c] and a[r][c] == '#':
                #  sr = r; sc = c; k = -1; l = 0
                #  for i in range(4):
                    #  nr = r + dr[i]
                    #  nc = c + dc[i]
                    #  if 0 <= nr < 1003 and 0 <= nc < 1003:
                        #  if a[nr][nc] == '#':
                            #  k = i
                            #  break
                #  if k != -1:
                    #  while a[r][c] == '#':
                        #  visited[r][c] = True
                        #  r = r + dr[k]
                        #  c = c + dc[k]
                        #  l += 1
                        #  if not (0 <= r < 1003 and 0 <= c < 1003):
                            #  break
                    #  cnt += 1
                    #  info = sr * (2**23) + sc * (2**13) + l*(2**2) + k
                    #  dat = dat * (2**33) + info
                    
                    #  print('{} {} {} {}'.format(sr, sc, l, k))
                    #  kk = info % (2**2)
                    #  info //= 2**2
                    #  ll = info % (2**11)
                    #  info //= 2**11
                    #  cc = info % (2**10)
                    #  info //= 2**10
                    #  rr = info % (2**10)
                    #  info //= 2**10
                    #  print('{} {} {} {}'.format(rr, cc, ll, kk))
                    #  k /= 0
                    #  dat += '{} {} {},'.format(sr, sc, l)
    b = dat.to_bytes(dat.bit_length(), byteorder='little')
    compressed = zlib.compress(b)
    compressed_b85 = base64.b85encode(compressed)
    #  compressed = base64.b85encode(zlib.compress(dat.encode('utf-8')))
    #  print(len(dat))
    #  print(len(str(compressed)))
    print(cnt, 'segments')
    print(len(str(b)))
    print(len(str(compressed)))
    print(len(str(compressed_b85)))


    decompressed = int.from_bytes(zlib.decompress(base64.b85decode(compressed_b85)), byteorder='little')
    print(dat == decompressed)

    print(str(compressed_b85))

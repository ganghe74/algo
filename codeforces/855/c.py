import sys
input=sys.stdin.readline
from heapq import heappush, heappop

t = int(input())
for _ in range(t):
    n = int(input())
    S = list(map(int,input().split()))
    z = s = 0
    pq = []
    for x in S[::-1]:
        if x == 0:
            z += 1
        elif len(pq) < z:
            heappush(pq, x)
        elif pq and x > pq[0]:
            heappop(pq)
            heappush(pq, x)
    print(sum(pq))
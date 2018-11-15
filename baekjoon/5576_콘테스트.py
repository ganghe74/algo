W = []
K = []
WScore = 0
KScore = 0
for i in range(10):
    W.append(int(input()))
for i in range(10):
    K.append(int(input()))
for i in range(3):
    WScore += max(W)
    W.remove(max(W))
for i in range(3):
    KScore += max(K)
    K.remove(max(K))
print(WScore, KScore)
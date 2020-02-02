#include <bits/stdc++.h>
using namespace std;

int N, M, m[100], c[100], d[100][10001];

int maxMemory(int i, int cost) {
    if (cost < 0) return -1e9;
    if (i >= N) return 0;
    if (d[i][cost] != -1) return d[i][cost];
    return d[i][cost] = max(maxMemory(i+1, cost), maxMemory(i+1, cost-c[i]) + m[i]);
}

int main() {
    memset(d, -1, sizeof(d));
    scanf("%d%d", &N, &M);
    for (int i=0;i<N;++i) scanf("%d", &m[i]);
    for (int i=0;i<N;++i) scanf("%d", &c[i]);
    int cost;
    for (cost=0;maxMemory(0, cost)<M;++cost);
    printf("%d", cost);
}

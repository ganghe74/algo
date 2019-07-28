#include <bits/stdc++.h>
using namespace std;

int N, K;
int W[100], V[100];
int d[100][100001];

int solve(int i, int w) {
    if (w < 0) return -1e9;
    if (i == -1) return 0;
    if (d[i][w] != -1) return d[i][w];
    return d[i][w] = max(solve(i-1, w), solve(i-1, w-W[i]) + V[i]);
}

int main() {
    memset(d, -1, sizeof(d));
    scanf("%d%d", &N, &K);
    for (int i=0;i<N;++i) scanf("%d%d", &W[i], &V[i]);
    printf("%d", solve(N-1, K));
}
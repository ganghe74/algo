#include <bits/stdc++.h>
using namespace std;

int d[101][101];

int main() {
    int N, M, u, v;
    scanf("%d%d", &N, &M);
    while (M--) {
        scanf("%d%d", &u, &v);
        d[u][v] = 1;
        d[v][u] = 1;
    }
    for (int k=1;k<=N;++k) {
        for (int i=1;i<=N;++i) {
            for (int j=1;j<=N;++j) {
                if (d[i][k] != 0 && d[k][j] != 0) {
                    if (!d[i][j]) d[i][j] = d[i][k]+d[k][j];
                    d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
                }
            }
        }
    }
    int m = 1e9, midx = 1;
    for (int i=1;i<=N;++i) {
        int n = 0;
        for (int j=1;j<=N;++j) n += d[i][j];
        if (n < m) {
            m = n;
            midx = i;
        }
    }
    printf("%d", midx);
}
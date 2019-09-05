#include <bits/stdc++.h>
using namespace std;
const int INF = 1e+9;
int d[101][101];
int main() {
    for (int i=1;i<=100;++i) {
        for (int j=1;j<=100;++j) {
            if (i == j) continue;
            d[i][j] = INF;
        }
    }
    int N, M;
    scanf("%d%d", &N, &M);
    while (M--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        d[a][b] = min(d[a][b], c);
    }
    for (int k=1;k<=N;++k) {
        for (int i=1;i<=N;++i) {
            for (int j=1;j<=N;++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    for (int i=1;i<=N;++i) {
        for (int j=1;j<=N;++j) {
            if (d[i][j] == INF) d[i][j] = 0;
            printf("%d ", d[i][j]);
        }
        puts("");
    }
}
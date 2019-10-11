#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int N, M, X, u, v, w, d[1001][1001];
int main() {
    for (int i=0;i<=1000;++i)
        for (int j=0;j<=1000;++j)
            if(i != j) d[i][j] = INF;
    scanf("%d%d%d", &N, &M, &X);
    while (M--) {
        scanf("%d%d%d", &u, &v, &w);
        d[u][v] = w;
    }
    for (int k=1;k<=N;++k) {
        for (int i=1;i<=N;++i) {
            for (int j=1;j<=N;++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    for (int i=1;i<=N;++i) M = max(M, d[i][X] + d[X][i]);
    printf("%d", M);
}
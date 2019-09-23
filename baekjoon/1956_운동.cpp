#include <bits/stdc++.h>
using namespace std;
int V, E, a, b, c, d[401][401];
const int INF = 1e7;
int main() {
    scanf("%d%d", &V, &E);
    for (int i=1;i<=V;++i)
        for (int j=1;j<=V;++j) d[i][j] = INF;
    while (E--) {
        scanf("%d%d%d", &a, &b, &c);
        d[a][b] = c;
    }
    for (int k=1;k<=V;++k) {
        for (int i=1;i<=V;++i) {
            for (int j=1;j<=V;++j) {
                if (i == j) continue;
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    int ans = INF;
    for (int i=1;i<=V;++i) {
        for (int j=1;j<=V;++j) {
            ans = min(ans, d[i][j] + d[j][i]);
        }
    }
    if (ans == INF) puts("-1");
    else printf("%d", ans);
}
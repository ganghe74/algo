#include <bits/stdc++.h>
using namespace std;

int n, m, r, t, a[101], d[101][101];

int main() {
    scanf("%d%d%d", &n, &m, &r);
    for (int i=1;i<=n;++i) scanf("%d", &a[i]);
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            if (i != j) d[i][j] = 1e6;
        }
    }
    while (r--) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        d[u][v] = w;
        d[v][u] = w;
    }
    for (int k=1;k<=n;++k) {
        for (int i=1;i<=n;++i) {
            for (int j=1;j<=n;++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    int ans = 0;
    for (int i=1;i<=n;++i) {
        int item = 0;
        for (int j=1;j<=n;++j)
            if (d[i][j] <= m) item += a[j];
        ans = max(ans, item);
    }
    printf("%d", ans);
}

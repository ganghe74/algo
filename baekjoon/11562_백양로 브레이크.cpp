#include <bits/stdc++.h>
using namespace std;

int n, m, k, u, v, b, d[251][251];

int main() {
    scanf("%d%d", &n, &m);
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
            d[i][j] = (i == j) ? 0 : 1e9;
    while (m--) {
        scanf("%d%d%d", &u, &v, &b);
        d[u][v] = 0;
        d[v][u] = !b;
    } 
    for (int k=1;k<=n;++k)
        for (int i=1;i<=n;++i)
            for (int j=1;j<=n;++j)
                if (d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];
    scanf("%d", &k);
    while (k--) {
        scanf("%d%d", &u, &v);
        printf("%d\n", d[u][v]);
    }
}

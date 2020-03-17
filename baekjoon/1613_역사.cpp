#include <bits/stdc++.h>
using namespace std;

int n, k, s, u, v;
vector<vector<int>> d;

int main() {
    scanf("%d%d", &n, &k);
    d.assign(n+1, vector<int>(n+1, 1e9));
    while (k--) {
        scanf("%d%d", &u, &v);
        d[u][v] = 1;
    }
    for (int k=1;k<=n;++k) {
        for (int i=1;i<=n;++i) {
            for (int j=1;j<=n;++j) {
                if (d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];
            }
        }
    }
    scanf("%d", &s);
    while (s--) {
        scanf("%d%d", &u, &v);
        if (d[u][v] < 1e9) puts("-1");
        else if (d[v][u] < 1e9) puts("1");
        else puts("0");
    }
}

#include <bits/stdc++.h>
using namespace std;

int n, u, v, w, energy[100000], p[17][100001], d[17][100001];
vector<pair<int,int>> a[100001];

void dfs(int u) {
    for (auto pi : a[u]) {
        auto [v, w] = pi;
        if (!d[0][v]) {
            p[0][v] = u;
            d[0][v] = w;
            dfs(v);
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i=0;i<n;++i) scanf("%d", &energy[i]);
    for (int i=1;i<n;++i) {
        scanf("%d%d%d", &u, &v, &w);
        a[u].push_back({v,w});
        a[v].push_back({u,w});
    }
    d[0][1] = 1e6;
    dfs(1);

    for (int i=1;i<17;++i) {
        for (int j=1;j<=n;++j) {
            p[i][j] = p[i-1][p[i-1][j]];
            d[i][j] = min(int(1e6), d[i-1][j] + d[i-1][p[i-1][j]]);
        }
    }

    for (int i=0;i<n;++i) {
        u = i+1;
        for (int j=16;j>=0;--j) {
            if (energy[i] >= d[j][u]) {
                energy[i] -= d[j][u];
                u = p[j][u];
            }
        }
        printf("%d\n", u);
    }
}

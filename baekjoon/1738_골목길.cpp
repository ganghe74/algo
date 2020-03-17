#include <bits/stdc++.h>
using namespace std;

int n, m, u, v, w, d[101], p[101];
vector<pair<int,int>> a[101];
bool path2n[101];

bool visited[101];
bool dfs(int u) {
    if (u == n) return true;
    visited[u] = 1;
    for (auto [v, w] : a[u])
        if (!visited[v])
            if(dfs(v)) return true;
    return false;
}

void f(int u) {
    if (u != 1) f(p[u]);
    printf("%d ", u);
}

int main() {
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d%d", &u, &v, &w);
        a[u].push_back({v, -w});
    }

    for (int i=1;i<=n;++i) {
        memset(visited, 0, sizeof(visited));
        path2n[i] = dfs(i);
    }
    fill(d, d+101, 1e9);
    d[1] = 0;
    bool ncycle = false;
    for (int i=0;i<n;++i) {
        for (int u=1;u<=n;++u) {
            for (auto [v, w] : a[u]) {
                if (d[u] + w < d[v]) {
                    d[v] = d[u] + w;
                    p[v] = u;
                    if (i == n-1 && path2n[u]) ncycle = true;
                }
            }
        }
    }
    if (ncycle || d[n] == 1e9) puts("-1");
    else f(n);
}

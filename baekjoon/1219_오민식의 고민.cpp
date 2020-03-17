#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int N, S, E, M, u, v, w, earn[101];
lint d[101];
vector<pair<int,int>> a[101];
bool visited[101], p2e[101];

bool dfs(int u) {
    if (u == E) return true;
    visited[u] = 1;
    for (auto [v, w] : a[u])
        if (!visited[v])
            if (dfs(v)) return true;
    return false;
}

int main() {
    scanf("%d%d%d%d", &N, &S, &E, &M);
    while (M--) {
        scanf("%d%d%d", &u, &v, &w);
        a[u].push_back({v, w});
    }
    for (int i=0;i<N;++i) scanf("%d", &earn[i]);
    for (int i=0;i<N;++i) {
        memset(visited, 0, sizeof(visited));
        p2e[i] = dfs(i);
    }
    fill(d, d+N, 1e18);
    d[S] = -earn[S];
    bool ncycle2e = false;
    for (int i=0;i<N;++i) {
        for (int u=0;u<N;++u) {
            for (auto [v, w] : a[u]) {
                w -= earn[v];
                if (d[u] != 1e18 && d[u] + w < d[v]) {
                    d[v] = d[u] + w;
                    if (i == N-1 && p2e[u]) ncycle2e = true;
                }
            }
        }
    }
    if (ncycle2e) puts("Gee");
    else if (d[E] == 1e18) puts("gg");
    else printf("%lld", -d[E]);
}

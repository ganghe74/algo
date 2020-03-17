#include <bits/stdc++.h>
using namespace std;

int T, N, M, u, v, w, d[1000];
bool path2s[1000], visited[1000];
vector<vector<pair<int,int>>> a;

bool dfs(int u) {
    if (u == 0) return true;
    visited[u] = 1;
    for (auto [v, w] : a[u])
        if (!visited[v])
            if(dfs(v)) return true;
    return false;
}

int main() {
    scanf("%d", &T);
    for (int tc=1;tc<=T;++tc) {
        scanf("%d%d", &N, &M);
        a.clear(); a.resize(N);
        while (M--) {
            scanf("%d%d%d", &u, &v, &w);
            a[u].push_back({v, w});
        }
        for (int i=0;i<N;++i) {
            memset(visited, 0, sizeof(visited));
            path2s[i] = dfs(i);
        }
        fill(d, d+N, 1e9);
        d[0] = 0;
        bool ok = false;
        for (int i=0;i<N;++i)
            for (int u=0;u<N;++u)
                for (auto [v, w] : a[u])
                    if (d[u] + w < d[v]) {
                        d[v] = d[u] + w;
                        if (i == N-1 && path2s[u]) ok = true;
                    }
        for (int i=0;i<N;++i)
            if (path2s[i] && d[i] < 0)
                ok = true;
        printf("Case #%d: %s\n", tc, ok ? "possible" : "not possible");
    }
}

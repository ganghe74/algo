#include <bits/stdc++.h>
using namespace std;

int t, n, m, u, v, d[2001];
vector<vector<int>> a;
bool f;

void dfs(int u) {
    if (f) return;
    for (int v : a[u]) {
        if (d[u] == d[v]) f = true;
        if (!d[v]) {
            d[v] = (d[u] == 1) ? 2 : 1;
            dfs(v);
        }
    }
}

int main() {
    scanf("%d", &t);
    for (int tc=0;tc<t;++tc) {
        scanf("%d%d", &n, &m);
        f = false;
        a.clear(); a.resize(n+1);
        memset(d, 0, sizeof(d));
        while (m--) {
            scanf("%d%d", &u, &v);
            a[u].push_back(v);
            a[v].push_back(u);
        }
        for (int i=1;i<+n;++i)
            if (!d[i]) d[i] = 1, dfs(i);
        if (tc) puts("");
        printf("Scenario #%d:\n", tc+1);
        if (f) puts("Suspicious bugs found!");
        else puts("No suspicious bugs found!");
    }
}

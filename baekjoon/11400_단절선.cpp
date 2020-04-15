#include <bits/stdc++.h>
using namespace std;

int V, E, u, v, cnt, dfsn[100001];
vector<vector<int>> a;
vector<pair<int,int>> bridges;

int dfs(int u, int p) {
    int ret = dfsn[u] = ++cnt;
    for (int v : a[u]) {
        if (v == p) continue;
        if (!dfsn[v]) {
            int low = dfs(v, u);
            ret = min(ret, low);
            if (low > dfsn[u]) bridges.push_back({min(u, v), max(u, v)});
        }
        else ret = min(ret, dfsn[v]);
    }
    return ret;
}

int main() {
    scanf("%d%d", &V, &E);
    a.resize(V+1);
    while (E--) {
        scanf("%d%d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    
    for (int i=1;i<=V;++i)
        if (!dfsn[i]) dfs(i, -1);
    
    sort(bridges.begin(), bridges.end());
    printf("%d\n", (int)bridges.size());
    for (auto [u, v] : bridges) printf("%d %d\n", u, v);
}


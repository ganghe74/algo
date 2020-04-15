#include <bits/stdc++.h>
using namespace std;

int V, E, u, v, cnt, dfsn[10001];
bool isCutVertex[10001];
vector<vector<int>> a;

int dfs(int u, bool root) {
    int ret = dfsn[u] = ++cnt;
    int child = 0;
    for (int v : a[u]) {
        if (!dfsn[v]) {
            child++;
            int low = dfs(v, 0);
            ret = min(ret, low);
            if (!root && low >= dfsn[u]) isCutVertex[u] = 1;
        }
        else ret = min(ret, dfsn[v]);
    }
    if (root && child >= 2) isCutVertex[u] = 1;
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
        if (!dfsn[i]) dfs(i, 1);

    vector<int> ans;
    for (int i=1;i<=V;++i)
        if (isCutVertex[i]) ans.push_back(i);

    printf("%d\n", (int)ans.size());
    for (int u : ans) printf("%d ", u);
}

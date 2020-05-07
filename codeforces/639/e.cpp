#include <bits/stdc++.h>
using namespace std;

int n, m, u, v, ind[200005], minafter[200005], minbefore[200005];
vector<int> adj[200005];

int dfs(int u) {
    int &ret = minafter[u];
    if (ret != -1) return ret;
    ret = u;
    for (int v : adj[u])
        ret = min(ret, dfs(v));
    return ret;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i=0;i<m;++i) {
        scanf("%d%d", &u, &v);
        u--; v--;
        adj[u].push_back(v);
        ind[v]++;
    }

    memset(minafter, -1, sizeof(minafter));
    for (int i=0;i<n;++i)
        if (minafter[i] == -1)
            dfs(i);

    fill(minbefore, minbefore+n, 1e9);
    queue<int> q;
    for (int i=0;i<n;++i) {
        if (!ind[i]) {
            minbefore[i] = i;
            q.push(i);
        }
    }
    
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            minbefore[v] = min({minbefore[u], minbefore[v], v});
            if (--ind[v] == 0)
                q.push(v);
        }
    }

    for (int i=0;i<n;++i) {
        if (ind[i]) {
            puts("-1");
            return 0;
        }
    }

    int cnt = 0;
    for (int i=0;i<n;++i)
        if (i == minbefore[i] && i == minafter[i])
            cnt++;

    printf("%d\n", cnt);
    for (int i=0;i<n;++i)
        if (i == minbefore[i] && i == minafter[i]) putchar('A');
        else putchar('E');
}

#include <bits/stdc++.h>
using namespace std;

int N, M, u, v, parent[100001], depth[100001], p[100001][17];
bool visited[100001];
vector<int> a[100001];

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u,v);
    int log;
    for (log=1;(1<<log)<=depth[u];++log);
    --log;
    for (int i=log;i>=0;--i)
        if (depth[u] - (1<<i) >= depth[v]) u = p[u][i];
    if (u == v) return u;
    for (int i=log;i>=0;--i) {
        if (p[u][i] != 0 && p[u][i] != p[v][i]) {
            u = p[u][i];
            v = p[v][i];
        }
    }
    return parent[u];
}

int main() {
    scanf("%d", &N);
    for (int i=1;i<N;++i) {
        scanf("%d%d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while (!q.empty()) {
        int now = q.front(); q.pop();
        for (int next : a[now]) {
            if (!visited[next]) {
                parent[next] = now;
                depth[next] = depth[now] + 1;
                visited[next] = true;
                q.push(next);
            }
        }
    }
    for (int i=1;i<=N;++i) p[i][0] = parent[i];
    for (int j=1;(1<<j)<N;++j) {
        for (int i=1;i<=N;++i) {
            if (p[i][j-1] != 0) p[i][j] = p[p[i][j-1]][j-1];
        }
    }
    scanf("%d", &M);
    while (M--) {
        scanf("%d%d", &u, &v);
        printf("%d\n", lca(u, v));
    }
}
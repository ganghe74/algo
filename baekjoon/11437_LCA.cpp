#include <bits/stdc++.h>
using namespace std;

vector<int> a[500001];
int N, M, u, v, parent[50001], depth[50001];
bool visited[50001];

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    while (depth[u] != depth[v]) u = parent[u];
    while (u != v) {
        u = parent[u];
        v = parent[v];
    }
    return u;
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
                visited[next] = true;
                parent[next] = now;
                depth[next] = depth[now] + 1;
                q.push(next);
            }
        }
    }
    scanf("%d", &M);
    while (M--) {
        scanf("%d%d", &u, &v);
        printf("%d\n", lca(u, v));
    }
}
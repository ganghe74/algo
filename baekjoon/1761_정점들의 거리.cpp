#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> a[40001];
int N, M, u, v, w, parent[40001], depth[40001], dist[40001];
bool visited[40001];

int lca(int u, int v) {
    int ret = 0;
    if (depth[u] < depth[v]) swap(u, v);
    while (depth[u] != depth[v]) {
        ret += dist[u];
        u = parent[u];
    }
    while (u != v) {
        ret += dist[u];
        ret += dist[v];
        u = parent[u];
        v = parent[v];
    }
    return ret;
}

int main() {
    scanf("%d", &N);
    for (int i=1;i<N;++i) {
        scanf("%d%d%d", &u, &v, &w);
        a[u].push_back({v, w});
        a[v].push_back({u, w});
    }
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while (!q.empty()) {
        int now = q.front(); q.pop();
        for (auto pi : a[now]) {
            int next = pi.first;
            int cost = pi.second;
            if (!visited[next]) {
                visited[next] = true;
                depth[next] = depth[now] + 1;
                parent[next] = now;
                dist[next] = cost;
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
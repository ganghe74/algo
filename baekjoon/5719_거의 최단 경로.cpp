#include <bits/stdc++.h>
using namespace std;

int N, M, S, D, u, v, w;
bool c[500][500];
vector<vector<pair<int,int>>> a;
vector<vector<int>> p;

vector<int> dijkstra(int src) {
    p.clear(); p.resize(N);
    vector<int> d(N, 1e9);
    d[src] = 0;
    priority_queue<pair<int,int>> pq;
    pq.push({0, src});
    while (!pq.empty()) {
        auto [dist, u] = pq.top(); pq.pop();
        if (-dist > d[u]) continue;
        for (auto [v, w] : a[u]) {
            if (c[u][v]) continue;
            int nextDist = -dist + w;
            if (nextDist == d[v]) p[v].push_back(u);
            if (nextDist < d[v]) {
                d[v] = nextDist;
                p[v].clear();
                p[v].push_back(u);
                pq.push({-nextDist, v});
            }
        }
    }
    return d;
}

bool visited[501];
void dfs(int u) {
    visited[u] = 1;
    for (int v : p[u])
        dfs(v), c[v][u] = 1;
}

int main() {
    while (scanf("%d%d%d%d", &N, &M, &S, &D) == 4) {
        a.clear(); a.resize(N);
        memset(c, 0, sizeof(c));
        memset(visited, 0, sizeof(visited));
        while (M--) {
            scanf("%d%d%d", &u, &v, &w);
            a[u].push_back({v, w});
        }
        dijkstra(S);
        dfs(D);
        int ans = dijkstra(S)[D];
        printf("%d\n", (ans == 1e9) ? -1 : ans);
    }
}

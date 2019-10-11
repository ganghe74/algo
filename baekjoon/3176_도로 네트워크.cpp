#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> adj;
bool visited[100001];
int depth[100001], parent[100001], p[100001][17], p_max[100001][17], p_min[100001][17];

void solve(int u, int v) {
    int Max = 0, Min = 1e9;
    if (depth[u] < depth[v]) swap(u, v);
    int log;
    for (log=1;(1<<log)<=depth[u];++log);
    --log;
    for (int i=log;i>=0;--i) {
        if (depth[u] - (1<<i) >= depth[v]) {
            Max = max(Max, p_max[u][i]);
            Min = min(Min, p_min[u][i]);
            u = p[u][i];
        }
    }
    if (u != v) {
        for (int i=log;i>=0;--i) {
            if (p[u][i] != 0 && p[u][i] != p[v][i]) {
                Max = max({Max, p_max[u][i], p_max[v][i]});
                Min = min({Min, p_min[u][i], p_min[v][i]});
                u = p[u][i];
                v = p[v][i];
            }
        }
        Max = max({Max, p_max[u][0], p_max[v][0]});
        Min = min({Min, p_min[u][0], p_min[v][0]});
    }
    printf("%d %d\n", Min, Max);
}

int main() {
    int N, K, u, v, w;
    scanf("%d", &N);
    adj.resize(N+1);
    for (int i=1;i<N;++i) {
        scanf("%d%d%d", &u, &v, &w);
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while (!q.empty()) {
        int now = q.front(); q.pop();
        for (auto pi : adj[now]) {
            int next = pi.first;
            int cost = pi.second;
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
                parent[next] = now;
                p[next][0] = now;
                p_min[next][0] = cost;
                p_max[next][0] = cost;
                depth[next] = depth[now] + 1;
            }
        }
    }
    for (int j=1;(1<<j)<N;++j) {
        for (int i=1;i<=N;++i) {
            if (p[i][j-1] != 0) {
                p[i][j] = p[p[i][j-1]][j-1];
                p_min[i][j] = min(p_min[i][j-1], p_min[p[i][j-1]][j-1]);
                p_max[i][j] = max(p_max[i][j-1], p_max[p[i][j-1]][j-1]);
            }
        }
    }
    scanf("%d", &K);
    while (K--) {
        scanf("%d%d", &u, &v);
        solve(u, v);
    }
}
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int N, M, X, u, v, w;
vector<vector<pair<int,int>>> adj, adj_inv;

vector<int> dijkstra(int src) {
    vector<int> dist(N+1, INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, src});
    dist[src] = 0;
    while (!pq.empty()) {
        int now = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        for (auto pi : adj[now]) {
            int next = pi.first;
            int nextDist = cost + pi.second;
            if (nextDist < dist[next]) {
                dist[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }
    return dist;
}

int main() {
    scanf("%d%d%d", &N, &M, &X);
    adj.resize(N+1); adj_inv.resize(N+1);
    while (M--) {
        scanf("%d%d%d", &u, &v, &w);
        adj[u].push_back({v, w});
        adj_inv[v].push_back({u, w});
    }
    auto dist = dijkstra(X);
    adj = adj_inv;
    auto dist_inv = dijkstra(X);
    for (int i=1;i<=N;++i) M = max(M, dist[i] + dist_inv[i]);
    printf("%d", M);
}
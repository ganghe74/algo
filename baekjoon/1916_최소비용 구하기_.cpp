#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 10000;
const int INF = 2e9;

int V, E, u, v, w, src, dst;
vector<pair<int,int>> adj[MAX_V];

vector<int> dijkstra(int src) {
    vector<int> dist(V+1, INF);
    dist[src] = 0;
    priority_queue<pair<int,int>> pq;
    pq.push({0, src});
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if (dist[here] < cost) continue;
        for (auto pi : adj[here]) {
            int there = pi.first;
            int nextDist = cost + pi.second;
            if (dist[there] > nextDist) {
                dist[there] = nextDist;
                pq.push({-nextDist, there});
            }
        }
    }
    return dist;
}

int main() {
    scanf("%d%d", &V, &E);
    while (E--) {
        scanf("%d%d%d", &u, &v, &w);
        adj[u].push_back({v, w});
    }
    scanf("%d%d", &src, &dst);
    printf("%d", dijkstra(src)[dst]);
}
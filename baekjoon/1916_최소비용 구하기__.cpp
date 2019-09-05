#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 10000;
const int INF = 2e9;

int V, E, u, v, w, src, dst;
vector<pair<int,int>> adj[MAX_V];

vector<int> dijkstra(int src) {
    vector<int> dist(V+1, INF);
    vector<bool> visited(V+1, false);
    dist[src] = 0; visited[src] = false;
    while (true) {
        int closest = INF, here;
        for (int i=0;i<V+1;++i)
            if (dist[i] < closest && !visited[i]) {
                here = i;
                closest = dist[i];
            }
        if (closest == INF) break;
        visited[here] = true;
        for (auto pi : adj[here]) {
            int there = pi.first;
            if (visited[there]) continue;
            int nextDist = dist[here] + pi.second;
            dist[there] = min(dist[there], nextDist);
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
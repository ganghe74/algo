#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> a[801];
int N, E, V1, V2, u, v, w;

vector<int> dijkstra(int src) {
    vector<int> d(N+1, 1e8);
    priority_queue<pair<int,int>> pq;
    d[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        int now = pq.top().second;
        int dist = -pq.top().first;
        pq.pop();
        for (auto pi : a[now]) {
            int next = pi.first;
            int nextDist = dist + pi.second;
            if (nextDist < d[next]) {
                d[next] = nextDist;
                pq.push({-nextDist, next});
            }
        }
    }
    return d;
}

int main() {
    scanf("%d%d", &N, &E);
    while (E--) {
        scanf("%d%d%d", &u, &v, &w);
        a[u].push_back({v, w});
        a[v].push_back({u, w});
    }
    scanf("%d%d", &V1, &V2);
    int ans = min(dijkstra(1)[V1] + dijkstra(V1)[V2] + dijkstra(V2)[N], dijkstra(1)[V2] + dijkstra(V2)[V1] + dijkstra(V1)[N]);
    if (ans >= 1e8) ans = -1;
    printf("%d", ans);
}
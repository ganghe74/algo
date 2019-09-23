#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int T, n, m, t, s, g, h, a, b, d, x, gh;
vector<vector<pair<int,int>>> adj;

vector<int> dijkstra(int src) {
    vector<int> dist(n+1, INF);
    vector<bool> visited(n+1, false);
    dist[src] = 0; visited[src] = false;
    while (true) {
        int closest = INF, here;
        for (int i=1;i<=n;++i)
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
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &n, &m, &t);
        scanf("%d%d%d", &s, &g, &h);
        adj.clear(); adj.resize(n+1);
        while (m--) {
            scanf("%d%d%d", &a, &b, &d);
            adj[a].push_back({b, d});
            adj[b].push_back({a, d});
            if ((a == g && b == h) || (a == h && b == g)) gh = d;
        }
        auto dist_s = dijkstra(s);
        auto dist_g = dijkstra(g);
        auto dist_h = dijkstra(h);
        vector<int> candidates;
        while (t--) {
            scanf("%d", &x);
            if (dist_s[x] == dist_s[g] + gh + dist_h[x] || dist_s[x] == dist_s[h] + gh + dist_g[x]) candidates.push_back(x);
        }
        sort(candidates.begin(), candidates.end());
        for (int ans : candidates) printf("%d ", ans);
        puts("");
    }
}
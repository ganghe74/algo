#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 10000;
const int INF = 1e9;

int V;
vector<pair<int,int>> adj[MAX_V];

// O(ElogE)
vector<int> dijkstra(int src) {
    vector<int> dist(V, INF);
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

// without priority_queue
// O(V^2)
vector<int> dijkstra2(int src) {
    vector<int> dist(V, INF);
    vector<bool> visited(V, false);
    dist[src] = 0; visited[src] = false;
    while (true) {
        int closest = INF, here;
        for (int i=0;i<V;++i)
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
    V = 6;
    adj[1].push_back({2, 2});
    adj[1].push_back({3, 3});
    adj[1].push_back({4, 1});
    adj[1].push_back({5, 10});
    adj[2].push_back({4, 2});
    adj[3].push_back({4, 1});
    adj[3].push_back({5, 1});
    adj[4].push_back({5, 3});
    for (int x : dijkstra(1)) printf("%d ", x);
    puts("");
    for (int x : dijkstra2(1)) printf("%d ", x);
    puts("");
}
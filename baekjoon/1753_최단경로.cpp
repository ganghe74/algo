#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e+9;
int V, E, K;
vector<pair<int,int>> a[20001];

vector<int> dijkstra(int src) {
    vector<int> dist(V+1, INF);
    dist[src] = 0;
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0, src));
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if (dist[here] < cost) continue;
        for (int i=0;i<a[here].size();++i) {
            int there = a[here][i].first;
            int nextDist = cost + a[here][i].second;
            if (dist[there] > nextDist) {
                dist[there] = nextDist;
                pq.push({-nextDist, there});
            }
        }
    }
    return dist;
}

int main() {
    scanf("%d %d", &V, &E);
    scanf("%d", &K);
    for (int i=0;i<E;++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        a[u].push_back({v,w});
    }
    vector<int> dist = dijkstra(K);
    for (int i=1;i<=V;++i) {
        if (dist[i] == INF) puts("INF");
        else printf("%d\n", dist[i]);
    }
}
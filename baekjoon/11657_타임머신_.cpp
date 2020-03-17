#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int MAX_V = 501;

int V, E, u, v, w;
vector<pair<int,int>> adj[MAX_V];

vector<int> bellmanFord(int src) {
    vector<int> upper(V, INF);
    upper[src] = 0;
    bool updated;
    for (int iter=0;iter<V;++iter) {
        updated = false;
        for (int here=0;here<V;++here)
            for (int i=0;i<adj[here].size();++i) {
                int there = adj[here][i].first;
                int cost = adj[here][i].second;
                if (upper[here] != INF && upper[there] > upper[here] + cost) {
                    upper[there] = upper[here] + cost;
                    updated = true;
                }
            }
        if (!updated) break;
    }
    if (updated) upper.clear();
    return upper;
}

int main() {
    scanf("%d%d", &V, &E);
    while (E--) {
        scanf("%d%d%d", &u, &v, &w);
        adj[u-1].push_back({v-1, w});
    }
    vector<int> d = bellmanFord(0);
    if (d.empty()) puts("-1");
    else for (int i=1;i<V;++i) printf("%d\n", (d[i] == INF) ? -1 : d[i]);
}

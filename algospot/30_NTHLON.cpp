#include <bits/stdc++.h>
using namespace std;

int V;
vector<pair<int,int>> adj[410];
const int START = 401;
const int INF = 1e+9;

int vertex(int delta) {
    return delta + 200;
}

vector<int> dijkstra(int start) {
    vector<int> dist(402, INF);
    priority_queue<pair<int,int>> pq;
    pq.push({0,start});
    dist[start] = 0;
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        for (int k=0;k<adj[now].size();++k) {
            int next = adj[now][k].first;
            int nextDist = cost + adj[now][k].second;
            if (nextDist < dist[next]) {
                dist[next] = nextDist;
                pq.push({-nextDist, next});
            }
        }
    }
    return dist;
}

int solve(const vector<int>& a, const vector<int> &b) {
    V = 402;
    for (int i=0;i<V;++i) adj[i].clear();
    for (int i=0;i<a.size();++i) {
        int delta = a[i] - b[i];
        adj[START].push_back({vertex(delta), a[i]});
    }
    for (int delta = -200; delta<=200;++delta) {
        for (int i=0;i<a.size();++i) {
            int next = delta + a[i] - b[i];
            if (abs(next) > 200) continue;
            adj[vertex(delta)].push_back({vertex(next), a[i]});
        }
    }
    vector<int> shortest = dijkstra(START);
    int ret = shortest[vertex(0)];
    if (ret == INF) return -1;
    return ret;
}

int main() {
    int C;
    scanf("%d", &C);
    while (C--) {
        int M, x, y;
        vector<int> a, b;
        scanf("%d", &M);
        while (M--) {
            scanf("%d %d", &x, &y);
            a.push_back(x);
            b.push_back(y);
        }
        int ans = solve(a, b);
        if (ans == -1) puts("IMPOSSIBLE");
        else printf("%d\n", ans);
    }
}
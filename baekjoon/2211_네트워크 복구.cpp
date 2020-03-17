#include <bits/stdc++.h>
using namespace std;

int N, M, u, v, w, d[1001], p[1001];
vector<pair<int,int>> a[1001];

int main() {
    scanf("%d%d", &N, &M);
    while (M--) {
        scanf("%d%d%d", &u, &v, &w);
        a[u].push_back({v, w});
        a[v].push_back({u, w});
    }
    fill(d, d+N+1, 1e9);
    d[1] = 0;
    priority_queue<pair<int,int>> pq;
    pq.push({0, 1});
    while (!pq.empty()) {
        auto [dist, u] = pq.top(); pq.pop();
        for (auto [v, cost] : a[u]) {
            int nextDist = -dist + cost;
            if (nextDist < d[v]) {
                d[v] = nextDist;
                p[v] = u;
                pq.push({-nextDist, v});
            }
        }
    }
    printf("%d\n", N-1);
    for (int i=2;i<=N;++i) printf("%d %d\n", i, p[i]);
}

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int N, M, K, u, v, w;
vector<pair<int,int>> a[10001];
vector<vector<lint>> d;

int main() {
    scanf("%d%d%d", &N, &M, &K);
    while (M--) {
        scanf("%d%d%d", &u, &v, &w);
        a[u].push_back({v, w});
        a[v].push_back({u, w});
    }
    d.assign(K+1, vector<lint>(N+1, 1e18));
    d[K][1] = 0;
    priority_queue<tuple<lint,int,int>> pq;
    pq.push({0,1,K});
    while (!pq.empty()) {
        auto [dist, u, k] = pq.top(); pq.pop();
        if (-dist > d[k][u]) continue;
        for (auto [v, w] : a[u]) {
            lint nextDist = -dist + w;
            if (nextDist < d[k][v]) {
                d[k][v] = nextDist;
                pq.push({-nextDist, v, k});
            }
            if (k) {
                nextDist = -dist;
                if (nextDist < d[k-1][v]) {
                    d[k-1][v] = -dist;
                    pq.push({-nextDist, v, k-1});
                }
            }
        }
    }
    lint ans = 1e18;
    for (int i=0;i<=K;++i) ans = min(ans, d[i][N]);
    printf("%lld", ans);
}

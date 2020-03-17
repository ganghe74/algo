#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int n, m, f, s, t, u, v, w;
vector<pair<int,int>> road[50000];
vector<int> flight[50000];
lint d[50000][2];

int main() {
    scanf("%d%d%d%d%d", &n, &m, &f, &s, &t);
    while (m--) {
        scanf("%d%d%d", &u, &v, &w);
        road[u].push_back({v, w});
        road[v].push_back({u, w});
    }
    while (f--) {
        scanf("%d%d", &u, &v);
        flight[u].push_back(v);
    }
    for (int i=0;i<n;++i) d[i][0] = d[i][1] = 1e18;
    d[s][1] = 0;
    priority_queue<tuple<lint,int,bool>> pq;
    pq.push({0, s, 1});
    while (!pq.empty()) {
        auto [dist, u, voucher] = pq.top(); pq.pop();
        for (auto [v, cost] : road[u]) {
            lint nextDist = -dist + cost;
            if (nextDist < d[v][voucher]) {
                d[v][voucher] = nextDist;
                pq.push({-nextDist, v, voucher});
            }
        }
        if (voucher) {
            for (int v : flight[u]) {
                lint nextDist = -dist;
                if (nextDist < d[v][0]) {
                    d[v][0] = nextDist;
                    pq.push({-nextDist, v, 0});
                }
            }
        }
    }
    printf("%lld", min(d[t][0], d[t][1]));
}

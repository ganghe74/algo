#include <bits/stdc++.h>
using namespace std;

int N, x, y, z, p[100000];
vector<pair<int,int>> a[3];

int Find(int u) {
    if (u == p[u]) return u;
    return p[u] = Find(p[u]);
}

void Union(int u, int v) {
    u = Find(u); v = Find(v);
    p[u] = v;
}

int main() {
    scanf("%d", &N);
    iota(p, p+N, 0);
    for (int i=0;i<N;++i) {
        scanf("%d%d%d", &x, &y, &z);
        a[0].push_back({x, i});
        a[1].push_back({y, i});
        a[2].push_back({z, i});
    }
    for (auto &vec : a) sort(vec.begin(), vec.end());
    priority_queue<tuple<int,int,int>> pq;
    for (int i=1;i<N;++i) {
        for (auto &vec : a) {
            int w = vec[i].first - vec[i-1].first;
            int u = vec[i-1].second;
            int v = vec[i].second;
            pq.push({-w, u, v});
        }
    }
    long long ans = 0;
    while (!pq.empty()) {
        auto [w, u, v] = pq.top(); pq.pop();
        if (Find(u) != Find(v)) {
            ans -= w;
            Union(u, v);
        }
    }
    printf("%lld", ans);
}

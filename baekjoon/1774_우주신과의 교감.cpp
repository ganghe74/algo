#include <bits/stdc++.h>
using namespace std;

int N, M, u, v, p[1000];
double ans, x[1000], y[1000];

int Find(int u) {
    if (u == p[u]) return u;
    return p[u] = Find(p[u]);
}

void Union(int u, int v) {
    u = Find(u); v = Find(v);
    p[u] = v;
}

int main() {
    scanf("%d%d", &N, &M);
    iota(p, p+N, 0);
    for (int i=0;i<N;++i)
        scanf("%lf%lf", &x[i], &y[i]);
    while (M--) {
        scanf("%d%d", &u, &v);
        Union(u-1, v-1);
    }
    priority_queue<tuple<double,int,int>> pq;
    for (int i=0;i<N;++i)
        for (int j=0;j<i;++j)
            pq.push({-hypot(x[i]-x[j], y[i]-y[j]), i, j});
    while (!pq.empty()) {
        auto [w, u, v] = pq.top(); pq.pop();
        if (Find(u) != Find(v)) {
            Union(u, v);
            ans -= w;
        }
    }
    printf("%.2lf", ans);
}

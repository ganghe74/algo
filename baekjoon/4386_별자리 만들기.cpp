#include <bits/stdc++.h>
using namespace std;

int n, p[100];
double ans, x[100], y[100];

int Find(int u) {
    if (u == p[u]) return u;
    return p[u] = Find(p[u]);
}

void Union(int u, int v) {
    u = Find(u); v = Find(v);
    p[u] = v;
}


int main() {
    scanf("%d", &n);
    iota(p, p+n, 0);
    for (int i=0;i<n;++i) scanf("%lf%lf", &x[i], &y[i]);
    priority_queue<tuple<double,int,int>> pq;
    for (int i=1;i<n;++i)
        for (int j=0;j<i;++j)
            pq.push({-hypot(x[i]-x[j], y[i]-y[j]), i, j});
    while (!pq.empty()) {
        auto [w, u, v] = pq.top(); pq.pop();
        if (Find(u) != Find(v)) {
            ans -= w;
            Union(u, v);
        }
    }
    printf("%lf", ans);
}

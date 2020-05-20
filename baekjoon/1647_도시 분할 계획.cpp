#include <bits/stdc++.h>
using namespace std;

int N, M, u, v, w, p[100001];

int Find(int u) {
    if (p[u] == u) return u;
    return p[u] = Find(p[u]);
}

void Union(int u, int v) {
    u = Find(u); v = Find(v);
    p[u] = v;
}

int main() {
    scanf("%d%d", &N, &M);
    vector<tuple<int,int,int>> edges;
    while (M--) {
        scanf("%d%d%d", &u, &v, &w);
        edges.push_back({w, u, v});
    }
    sort(edges.begin(), edges.end());
    iota(p, p+N+1, 0);

    int s = 0, m = 0;
    for (auto [w, u, v] : edges) {
        if (Find(u) != Find(v)) {
            Union(u, v);
            s += w;
            m = w;
        }
    }
    printf("%d", s-m);
}

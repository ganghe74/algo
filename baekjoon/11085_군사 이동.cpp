#include <bits/stdc++.h>
using namespace std;

int p, w, c, v, parent[1000];
vector<tuple<int,int,int>> edges;

int Find(int u) {
    if (u == parent[u]) return u;
    return parent[u] = Find(parent[u]);
}

void Union(int u, int v) {
    u = Find(u); v = Find(v);
    parent[u] = v;
}

int main() {
    scanf("%d%d%d%d", &p, &w, &c, &v);
    for (int i=0;i<w;++i) {
        int start, end, width;
        scanf("%d%d%d", &start, &end, &width);
        edges.push_back({width, start, end});
    }

    iota(parent, parent+p, 0);
    sort(edges.begin(), edges.end());
    reverse(edges.begin(), edges.end());

    for (auto edge : edges) {
        auto [width, start, end] = edge;
        Union(start, end);
        if (Find(c) == Find(v)) {
            printf("%d", width);
            break;
        }
    }
}

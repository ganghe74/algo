#include <bits/stdc++.h>
using namespace std;

int n, m, u, v, ind[50000], p[50000];
char ch;
vector<int> a[50000];

int Find(int u) {
    if (p[u] == u) return u;
    return p[u] = Find(p[u]);
}

void Union(int u, int v) {
    u = Find(u); v = Find(v);
    p[u] = v;
}

int main() {
    scanf("%d%d", &n, &m);
    iota(p, p+n, 0);
    queue<pair<int,int>> edges;
    while (m--) {
        scanf("%d %c %d", &u, &ch, &v);
        if (ch == '=')
            Union(u, v);
        else
            edges.push({u, v});
    }
    while (!edges.empty()) {
        auto [u, v] = edges.front(); edges.pop();
        u = Find(u); v = Find(v);
        a[u].push_back(v);
        ind[v]++;
    }

    queue<int> q;
    for (int i=0;i<n;++i)
        if (Find(i) == i && !ind[i])
            q.push(i);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : a[u]) {
            if (--ind[v] == 0) {
                q.push(v);
            }
        }
    }
    for (int i=0;i<n;++i)
        if (ind[i]) {
            puts("inconsistent");
            return 0;
        }
    puts("consistent");
}

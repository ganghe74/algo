#include <bits/stdc++.h>
using namespace std;

int n, r, q, u, v, d[100001];
vector<int> a[100001];

int dfs(int u, int p) {
    d[u] = 1;
    for (int v : a[u]) {
        if (v == p) continue;
        d[u] += dfs(v, u);
    }
    return d[u];
}

int main() {
    scanf("%d%d%d", &n, &r, &q);
    for (int i=1;i<n;++i) {
        scanf("%d%d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(r, -1);
    while (q--) {
        scanf("%d", &u);
        printf("%d\n", d[u]);
    }
}

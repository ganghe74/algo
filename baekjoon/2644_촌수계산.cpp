#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, u, v, d[101];
vector<int> a[101];

void dfs(int u) {
    for (int v : a[u]) {
        if (!d[v]) {
            d[v] = d[u] + 1;
            dfs(v);
        }
    }
}

int main() {
    scanf("%d%d%d%d", &n, &u, &v, &m);
    while (m--) {
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(u);
    if (d[v]) printf("%d", d[v]);
    else puts("-1");
}

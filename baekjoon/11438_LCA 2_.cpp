#include <bits/stdc++.h>
using namespace std;

vector<int> a[100001];
int timer, p[100001][18], tin[100001], tout[100001];

int dfs(int v, int parent) {
    tin[v] = ++timer;
    p[v][0] = parent;
    for (int i=1;i<=17;++i) p[v][i] = p[p[v][i-1]][i-1];
    for (int to : a[v]) {
        if (to != parent) dfs(to, v);
    }
    tout[v] = ++timer;
}

bool upper(int u, int v) {
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int lca(int u, int v) {
    if (upper(u, v)) return u;
    if (upper(v, u)) return v;
    for (int i=17;i>=0;--i) {
        if (!upper(p[u][i], v)) u = p[u][i];
    }
    return p[u][0];
}

int main() {
    int N, M, u, v;
    scanf("%d", &N);
    for (int i=1;i<N;++i) {
        scanf("%d%d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1, 1);
    scanf("%d", &M);
    while (M--) {
        scanf("%d%d", &u, &v);
        printf("%d\n", lca(u, v));
    }
}
// https://www.acmicpc.net/problem/11437
#include <bits/stdc++.h>
using namespace std;

vector<int> a[100001];
int timer, p[100001][18], tin[100001], tout[100001], depth[100001];

int dfs(int v, int parent) {
    tin[v] = ++timer;
    p[v][0] = parent;
    depth[v] = depth[parent] + 1;
    for (int i=1;i<=17;++i) p[v][i] = p[p[v][i-1]][i-1];
    for (int to : a[v]) {
        if (to != parent) dfs(to, v);
    }
    tout[v] = ++timer;
}

bool upper(int u, int v) {
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

// O(N)
int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    while (depth[u] != depth[v]) u = p[u][0];
    while (u != v) {
        u = p[u][0];
        v = p[v][0];
    }
    return u;
}

// O(logN)
int lca2(int u, int v) {
    if (depth[u] < depth[v]) swap(u,v);
    int log;
    for (log=1;(1<<log)<=depth[u];++log);
    --log;
    for (int i=log;i>=0;--i)
        if (depth[u] - (1<<i) >= depth[v]) u = p[u][i];
    if (u == v) return u;
    for (int i=log;i>=0;--i) {
        if (p[u][i] != 0 && p[u][i] != p[v][i]) {
            u = p[u][i];
            v = p[v][i];
        }
    }
    return p[u][0];
}

// O(logN)
int lca3(int u, int v) {
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
        printf("%d %d %d\n", lca(u, v), lca2(u, v), lca3(u, v));
    }
}
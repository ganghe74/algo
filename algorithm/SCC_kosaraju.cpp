// https://www.acmicpc.net/problem/2150
#include <bits/stdc++.h>
using namespace std;

int V, E, u, v;
bool visited[10001];
stack<int> st;
vector<int> scc;
vector<vector<int>> a, ar, sccs;

void dfs(int u, bool inv) {
    visited[u] = 1;
    auto &g = inv ? ar : a;
    for (int v : g[u]) {
        if (!visited[v])
            dfs(v, inv);
    }
    if (inv) scc.push_back(u);
    else st.push(u);
}

void kosaraju() {
    memset(visited, 0, sizeof(visited));
    for (int i=1;i<=V;++i)
        if (!visited[i]) dfs(i, 0);
    memset(visited, 0, sizeof(visited));
    while (!st.empty()) {
        int u = st.top(); st.pop();
        scc.clear();
        if (!visited[u]) {
            dfs(u, 1);
            sccs.push_back(scc);
        }
    }
}

int main() {
    scanf("%d%d", &V, &E);
    a.resize(V+1); ar.resize(V+1);
    while (E--) {
        scanf("%d%d", &u, &v);
        a[u].push_back(v);
        ar[v].push_back(u);
    }
    kosaraju();
    for (auto &scc : sccs) sort(scc.begin(), scc.end());
    sort(sccs.begin(), sccs.end());
    printf("%d\n", sccs.size());
    for (auto &scc : sccs) {
        for (int u : scc) printf("%d ", u);
        puts("-1");
    }
}

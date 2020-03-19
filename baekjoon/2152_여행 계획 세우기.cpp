#include <bits/stdc++.h>
using namespace std;

int N, M, S, T, u, v, cnt, dfsn[10001], sn[10001], ind[10001], d[10001];
bool finished[10001], reachable[10001];
vector<int> a[10001], sa[10000];
vector<vector<int>> scc;
stack<int> st;

int dfs(int u) {
    int result = dfsn[u] = ++cnt;
    st.push(u);
    for (int v : a[u]) {
        if (!dfsn[v]) result = min(result, dfs(v));
        else if (!finished[v]) result = min(result, dfsn[v]);
    }
    if (result == dfsn[u]) {
        vector<int> currSCC;
        while (true) {
            int t = st.top(); st.pop();
            currSCC.push_back(t);
            finished[t] = 1;
            sn[t] = scc.size();
            if (u == t) break;
        }
        scc.push_back(currSCC);
    }
    return result;
}

int main() {
    scanf("%d%d%d%d", &N, &M, &S, &T);
    while (M--) {
        scanf("%d%d", &u, &v);
        a[u].push_back(v);
    }
    for (int i=1;i<=N;++i)
        if (!dfsn[i]) dfs(i);
    for (int u=1;u<=N;++u)
        for (int v : a[u])
            if (sn[u] != sn[v]) {
                ind[sn[v]]++;
                sa[sn[u]].push_back(sn[v]);
            }
    reachable[sn[S]] = 1;
    queue<int> q;
    for (int i=0;i<scc.size();++i) {
        d[i] = scc[i].size();
        if (!ind[i]) q.push(i);
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : sa[u]) {
            if (reachable[u]) {
                reachable[v] = 1;
                d[v] = max(d[v], d[u] + (int)scc[v].size());
            }
            if (--ind[v] == 0) q.push(v);
        }
    }
    if (reachable[sn[T]]) printf("%d", d[sn[T]]);
    else puts("0");
}

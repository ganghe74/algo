#include <bits/stdc++.h>
using namespace std;

int N, M, u, v, site, cnt, dfsn[5000], sn[5000], sind[5000];
long long d[5000];
bool finished[5000];
vector<vector<int>> a, sa, scc;
stack<int> st;
unordered_map<string, int> m;
string s;

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
            if (t == u) break;
        }
        scc.push_back(currSCC);
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    a.resize(5000); sa.resize(5000);
    cin >> N;
    while (N--) {
        cin >> s;
        if (!m[s]) m[s] = ++site;
        v = m[s];
        cin >> M;
        while (M--) {
            cin >> s;
            if (!m[s]) m[s] = ++site;
            u = m[s];
            a[u].push_back(v);
        }
    }
    for (int i=1;i<=site;++i)
        if (!dfsn[i]) dfs(i);
    for (int u=1;u<=site;++u)
        for (int v : a[u])
            if (sn[u] != sn[v]) {
                sind[sn[v]]++;
                sa[sn[u]].push_back(sn[v]);
            }
    queue<int> q, ordered_q;
    for (int u=0;u<scc.size();++u)
        if (!sind[u]) q.push(u);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        ordered_q.push(u);
        for (int v : sa[u])
            if (--sind[v] == 0) q.push(v);
    }
    fill(d, d+5000, 1);
    while (!ordered_q.empty()) {
        int su = ordered_q.front(); ordered_q.pop();
        for (int u : scc[su]) {
            for (int v : a[u]) {
                if (sn[u] == sn[v]) continue;
                d[v] += d[u];
            }
        }
    }
    cin >> s;
    u = m[s];
    cout << d[u];
}

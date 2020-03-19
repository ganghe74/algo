#include <bits/stdc++.h>
using namespace std;

int n, m, u, v, cnt, dfsn[5001], sn[5001], outd[5001];
bool finished[5001];
vector<vector<int>> a, scc;
stack<int> st;

int dfs(int u) {
    int result = dfsn[u] = ++cnt;
    st.push(u);
    for (int v : a[u]) {
        if (!dfsn[v]) result = min(result, dfs(v));
        else if (!finished[v]) result = min(result, dfsn[v]);
    }
    if (dfsn[u] == result) {
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
    while (scanf("%d%d", &n, &m) == 2) {
        scc.clear();
        a.clear(); a.resize(n+1);
        memset(dfsn, 0, sizeof(dfsn));
        memset(finished, 0, sizeof(finished));
        memset(outd, 0, sizeof(outd));
        while (m--) {
            scanf("%d%d", &u, &v);
            a[u].push_back(v);
        }
        for (int i=1;i<=n;++i)
            if (!dfsn[i]) dfs(i);
        for (int u=1;u<=n;++u)
            for (int v : a[u])
                if (sn[u] != sn[v]) outd[sn[u]]++;
        vector<int> ans;
        for (int i=0;i<scc.size();++i)
            if (!outd[i])
                for (int u : scc[i]) ans.push_back(u);
        sort(ans.begin(), ans.end());
        for (int u : ans) printf("%d ", u);
        puts("");
    }
}

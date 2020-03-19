#include <bits/stdc++.h>
using namespace std;

int t, n, cnt, dfsn[300], sn[300], a[300][300], sd[300][300];
bool finished[300];
vector<vector<int>> scc;
stack<int> st;

int dfs(int u) {
    int result = dfsn[u] = ++cnt;
    st.push(u);
    for (int v=0;v<n;++v) {
        if (a[u][v]) {
            if (!dfsn[v]) result = min(result, dfs(v));
            else if (!finished[v]) result = min(result, dfsn[v]);
        }
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
    scanf("%d", &t);
    while (t--) {
        cnt = 0;
        scc.clear();
        memset(a, 0, sizeof(a));
        memset(dfsn, 0, sizeof(dfsn));
        memset(finished, 0, sizeof(finished));
        scanf("%d", &n);
        for (int i=0;i<n;++i)
            for (int j=0;j<n;++j) scanf("%1d", &a[i][j]);
        for (int i=0;i<n;++i)
            if (!dfsn[i]) dfs(i);
        for (int i=0;i<scc.size();++i)
            for (int j=0;j<scc.size();++j)
                sd[i][j] = (i == j) ? 0 : 1e9;
        for (int u=0;u<n;++u)
            for (int v=0;v<n;++v)
                if (a[u][v] && sn[u] != sn[v])
                    sd[sn[u]][sn[v]] = -1;
        for (int k=0;k<scc.size();++k)
            for (int i=0;i<scc.size();++i)
                for (int j=0;j<scc.size();++j)
                    if (sd[i][k] + sd[k][j] < sd[i][j])
                        sd[i][j] = sd[i][k] + sd[k][j];
        vector<pair<int,int>> ans;
        for (int i=0;i<scc.size();++i)
            for (int j=0;j<scc.size();++j)
                if (sd[i][j] == -1) ans.push_back({scc[i][0], scc[j][0]});
        for (int i=0;i<scc.size();++i) {
            if (scc[i].size() == 1) continue;
            for (int j=1;j<scc[i].size();++j) ans.push_back({scc[i][j-1], scc[i][j]});
            ans.push_back({scc[i].back(), scc[i][0]});
        }
        printf("%d\n", ans.size());
        for (auto [u, v] : ans) printf("%d %d\n", u+1, v+1);
        if (t) puts("");
    }
}

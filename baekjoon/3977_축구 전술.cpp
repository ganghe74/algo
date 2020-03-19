#include <bits/stdc++.h>
using namespace std;

int T, N, M, u, v, cnt, dfsn[100000], sn[100000], ind[100000];
bool finished[100000];
stack<int> st;
vector<vector<int>> a, scc;

int dfs(int u) {
    dfsn[u] = ++cnt;
    st.push(u);

    int result = dfsn[u];
    for (int v : a[u]) {
        if (!dfsn[v]) result = min(result, dfs(v));
        else if (!finished[v]) result = min(result, dfsn[v]);
    }

    if (result == dfsn[u]) {
        vector<int> currSCC;
        while (true) {
            int t = st.top(); st.pop();
            currSCC.push_back(t);
            finished[t] = true;
            sn[t] = scc.size();
            if (t == u) break;
        }
        scc.push_back(currSCC);
    }
    return result;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &N, &M);
        cnt = 0;
        scc.clear();
        a.clear(); a.resize(N);
        memset(dfsn, 0, sizeof(dfsn));
        memset(finished, 0, sizeof(finished));
        memset(ind, 0, sizeof(ind));
        while (M--) {
            scanf("%d%d", &u, &v);
            a[u].push_back(v);
        }
        for (int i=0;i<N;++i)
            if (!finished[i]) dfs(i);
        for (int u=0;u<N;++u)
            for (int v : a[u])
                if (sn[u] != sn[v]) ind[sn[v]]++;
        cnt = 0;
        for (int i=0;i<scc.size();++i)
            if (!ind[i]) u = i, cnt++;
        if (cnt != 1) puts("Confused");
        else {
            sort(scc[u].begin(), scc[u].end());
            for (int x : scc[u]) printf("%d\n", x);
        }
        puts("");
    }
}

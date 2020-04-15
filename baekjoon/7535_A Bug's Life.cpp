#include <bits/stdc++.h>
using namespace std;

int t, n, m, u, v, cnt, scnt, dfsn[8000], sn[8000];
bool finished[8000];
vector<vector<int>> a;
stack<int> st;

int oppo(int n) { return n%2 ? n-1 : n+1; }

int dfs(int u) {
    int ret = dfsn[u] = ++cnt;
    st.push(u);
    for (int v : a[u]) {
        if (!dfsn[v]) ret = min(ret, dfs(v));
        else if (!finished[v]) ret = min(ret, dfsn[v]);
    }
    if (dfsn[u] == ret) {
        scnt++;
        while (true) {
            int t = st.top(); st.pop();
            finished[t] = 1;
            sn[t] = scnt;
            if (t == u) break;
        }
    }
    return ret;
}

int main() {
    scanf("%d", &t);
    for (int tc=0;tc<t;++tc) {
        scanf("%d%d", &n, &m);
        cnt = scnt = 0;
        a.clear(); a.resize(4*n);
        memset(dfsn, 0, sizeof(dfsn));
        memset(finished, 0, sizeof(finished));
        while (m--) {
            scanf("%d%d", &u, &v);
            u = u*2-1;
            v = v*2-1;
            a[u].push_back(oppo(v));
            a[v].push_back(oppo(u));
            a[oppo(u)].push_back(v);
            a[oppo(v)].push_back(u);
        }
        dfs(0);
        for (int i=0;i<4*n;++i)
            if (!dfsn[i]) dfs(i);
        bool suspicious = false;
        for (int i=0;i<2*n;++i)
            if (sn[i*2] == sn[i*2+1]) suspicious = true;
        if (tc) puts("");
        printf("Scenario #%d:\n", tc+1);
        if (suspicious) puts("Suspicious bugs found!");
        else puts("No suspicious bugs found!");
    }
}

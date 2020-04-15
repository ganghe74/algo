#include <bits/stdc++.h>
using namespace std;

int n, m, u, v, cnt, scnt, dfsn[2000], sn[2000];
bool finished[2000];
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
    if (ret == dfsn[u]) {
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
    while (scanf("%d%d", &n, &m) == 2) {
        cnt = scnt = 0;
        a.clear(); a.resize(n*2);
        memset(dfsn, 0, sizeof(dfsn));
        memset(finished, 0, sizeof(finished));
        while (m--) {
            scanf("%d%d", &u, &v);
            u = (u < 0) ? -(u+1)*2 : u*2-1;
            v = (v < 0) ? -(v+1)*2 : v*2-1;
            a[oppo(u)].push_back(v);
            a[oppo(v)].push_back(u);
        }
        a[0].push_back(1);
        for (int i=0;i<2*n;++i)
            if (!dfsn[i]) dfs(i);
        
        bool doubt = false;
        for (int i=0;i<n;++i) {
            if (sn[i*2] == sn[i*2+1]) {
                doubt = true;
                break;
            }
        }
        puts(doubt ? "no" : "yes");
    }
}

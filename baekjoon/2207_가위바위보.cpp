#include <bits/stdc++.h>
using namespace std;

int N, M, u, v, cnt, scnt, dfsn[20000], sn[20000];
bool finished[20000];
vector<int> a[20000];
stack<int> st;

int oppo(int n) { return n % 2 ? n - 1 : n + 1; }

int dfs(int u) {
    int ret = dfsn[u] = ++cnt;
    st.push(u);
    for (int v: a[u]) {
        if (!dfsn[v]) ret = min(ret, dfs(v));
        else if (!finished[v]) ret = min(ret, dfsn[v]);
    }
    if (ret == dfsn[u]) {
        scnt++;
        while (true) {
            int t = st.top(); st.pop();
            sn[t] = scnt;
            finished[t] = 1;
            if (t == u) break;
        }
    }
    return ret;
}

int main() {
    scanf("%d%d", &N, &M);
    while (N--) {
        scanf("%d%d", &u, &v);
        u = (u < 0) ? -(u+1)*2 : u*2-1;
        v = (v < 0) ? -(v+1)*2 : v*2-1;
        a[oppo(u)].push_back(v);
        a[oppo(v)].push_back(u);
    }
    for (int i=0;i<2*M;++i)
        if (!dfsn[i]) dfs(i);
    for (int i=0;i<M;++i) {
        if (sn[i*2] == sn[i*2+1]) {
            puts("OTL");
            return 0;
        }
    }
    puts("^_^");
}

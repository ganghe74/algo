#include <bits/stdc++.h>
using namespace std;

int N, M, K, u, v, cnt, scnt, dfsn[200000], sn[200000], on[100000];
bool finished[200000];
vector<int> a[200000], btn[100000];
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
    scanf("%d%d", &N, &M);
    for (int i=0;i<N;++i) scanf("%d", on+i);
    for (int i=0;i<M;++i) {
        scanf("%d", &K);
        while (K--) {
            scanf("%d", &u);
            btn[u-1].push_back(i);
        }
    }
    for (int i=0;i<N;++i) {
        u = btn[i][0]*2+1;
        v = btn[i][1]*2+1;
        if (on[i]) {
            a[u].push_back(v);
            a[v].push_back(u);
            a[oppo(u)].push_back(oppo(v));
            a[oppo(v)].push_back(oppo(u));
        }
        else {
            a[u].push_back(oppo(v));
            a[v].push_back(oppo(u));
            a[oppo(u)].push_back(v);
            a[oppo(v)].push_back(u);
        }
    }
    for (int i=0;i<2*M;++i)
        if (!dfsn[i]) dfs(i);
    for (int i=0;i<M;++i) {
        if (sn[i*2] == sn[i*2+1]) {
            puts("0");
            return 0;
        }
    }
    puts("1");
}

#include <bits/stdc++.h>
using namespace std;

int T, N, M, K, cnt, scnt, dfsn[4000], sn[4000];
bool finished[4000];
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
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &N, &M, &K);
        cnt = scnt = 0;
        a.clear(); a.resize(2*(N+M));
        memset(dfsn, 0, sizeof(dfsn));
        memset(finished, 0, sizeof(finished));
        while (K--) {
            int r1, c1, r2, c2;
            scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
            r1 = r1*2-1;
            r2 = r2*2-1;
            c1 = (c1+N)*2-1;
            c2 = (c2+N)*2-1;
            if (r1 > r2) {
                c1 = oppo(c1);
                c2 = oppo(c2);
            }
            if (c1 > c2) {
                r1 = oppo(r1);
                r2 = oppo(r2);
            }
            a[oppo(r1)].push_back(c1);
            a[oppo(c1)].push_back(r1);
            a[oppo(r2)].push_back(c2);
            a[oppo(c2)].push_back(r2);
            if (r1 != r2) {
                a[oppo(c1)].push_back(c2);
                a[oppo(c2)].push_back(c1);
            }
            if (c1 != c2) {
                a[oppo(r1)].push_back(r2);
                a[oppo(r2)].push_back(r1);
            }
        }
        for (int i=0;i<2*(N+M);++i)
            if (!dfsn[i]) dfs(i);
        bool ok = true;
        for (int i=0;i<N+M;++i)
            if (sn[i*2] == sn[i*2+1]) ok = false;
        puts(ok ? "Yes" : "No");
    }
}

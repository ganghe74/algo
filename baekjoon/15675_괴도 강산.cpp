#include <bits/stdc++.h>
using namespace std;

int N, M, cnt, scnt, dfsn[4000], sn[4000];
bool finished[4000];
vector<int> a[4000];
stack<int> st;

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

int oppo(int n) { return n%2 ? n-1 : n+1; }

int main() {
    scanf("%d%d", &N, &M);
    char c;
    for (int i=0;i<N;++i) {
        for (int j=0;j<M;++j) {
            scanf(" %c", &c);
            int u = i*2+1;
            int v = (N+j)*2+1;
            if (c == '#') {
                a[u].push_back(v);
                a[v].push_back(u);
                a[oppo(u)].push_back(oppo(v));
                a[oppo(v)].push_back(oppo(u));
            }
            if (c == '*') {
                a[u].push_back(oppo(v));
                a[v].push_back(oppo(u));
                a[oppo(u)].push_back(v);
                a[oppo(v)].push_back(u);
            }
        }
    }
    for (int i=0;i<2*(N+M);++i)
        if (!dfsn[i]) dfs(i);

    for (int i=0;i<N+M;++i)
        if (sn[i*2] == sn[i*2+1]) {
            puts("0");
            return 0;
        }
    puts("1");
}

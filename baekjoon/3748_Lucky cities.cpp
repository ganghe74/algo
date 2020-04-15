#include <bits/stdc++.h>
using namespace std;

int T, N, M, u, v, cnt, dfsn[100010];
bool lucky[100010];
vector<vector<int>> a;
vector<vector<pair<int,int>>> bcc;
stack<pair<int,int>> st;

int dfs(int u, int p) {
    int ret = dfsn[u] = ++cnt;
    for (int v : a[u]) {
        if (v == p) continue;
        if (dfsn[u] > dfsn[v]) st.push({u, v});
        if (!dfsn[v]) {
            int low = dfs(v, u);
            ret = min(ret, low);
            if (low >= dfsn[u]) {
                vector<pair<int,int>> bc;
                while (st.top() != make_pair(u, v))
                    bc.push_back(st.top()), st.pop();
                bc.push_back(st.top()), st.pop();
                bcc.push_back(bc);
            }
        }
        else ret = min(ret, dfsn[v]);
    }
    return ret;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &N, &M);
        cnt = 0;
        bcc.clear();
        a.clear(); a.resize(N+1);
        fill(dfsn, dfsn+N+1, 0);
        fill(lucky, lucky+N+1, 0);
        while (M--) {
            scanf("%d%d", &u, &v);
            a[u].push_back(v);
            a[v].push_back(u);
        }
        for (int i=1;i<=N;++i)
            if (!dfsn[i]) dfs(i, -1);

        for (auto &bc : bcc) {
            bool oddcycle = false;
            unordered_map<int,vector<int>> adj;
            unordered_map<int,int> d;
            for (auto [u, v] : bc) {
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            
            int start = bc[0].first;
            d[start] = 1;
            queue<int> q;
            q.push(start);

            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : adj[u]) {
                    if (!d[v]) {
                        d[v] = d[u] + 1;
                        q.push(v);
                    }
                    else if (d[u] == d[v]) oddcycle = true;
                }
            }
            if (oddcycle)
                for (auto [u, v] : bc) lucky[u] = lucky[v] = 1;
        }

        int ans = 0;
        for (int i=1;i<=N;++i)
            if (lucky[i]) ans++;
        printf("%d\n", ans);
    }
}

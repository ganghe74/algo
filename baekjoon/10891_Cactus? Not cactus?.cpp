#include <bits/stdc++.h>
using namespace std;

int N, M, u, v, cnt, dfsn[100001], bccnt[100001];
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
                vector<pair<int,int>> currBCC;
                while (!st.empty() && st.top() != make_pair(u, v))
                    currBCC.push_back(st.top()), st.pop();
                currBCC.push_back(st.top()); st.pop();
                bcc.push_back(currBCC);
            }
        }
        else ret = min(ret, dfsn[v]);
    }
    return ret;
}

int main() {
    scanf("%d%d", &N, &M);
    a.resize(N+1);
    while (M--) {
        scanf("%d%d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }

    for (int i=1;i<=N;++i)
        if (!dfsn[i]) dfs(i, -1);

    for (auto &bc : bcc) {
        if (bc.size() == 1) continue;
        set<int> s;
        for (auto [u, v] : bc)
            s.insert(u), s.insert(v);
        if (s.size() != bc.size()) {
            puts("Not cactus");
            return 0;
        }
        for (int u : s) bccnt[u]++;
    }

    for (int i=1;i<=N;++i)
        if (bccnt[i] >= 2) {
            puts("Not cactus");
            return 0;
        }

    puts("Cactus");
}

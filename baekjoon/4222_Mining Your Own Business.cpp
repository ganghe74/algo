#include <bits/stdc++.h>
using namespace std;

int N, tc, u, v, cnt, dfsn[100000];
bool isCutVertex[100000];
vector<vector<int>> a;
vector<vector<pair<int,int>>> bcc;
stack<pair<int,int>> st;

int dfs(int u, int p) {
    int ret = dfsn[u] = ++cnt;
    int child = 0;
    for (int v : a[u]) {
        if (p == v) continue;
        if (dfsn[u] > dfsn[v]) st.push({u, v});
        if (!dfsn[v]) {
            child++;
            int low = dfs(v, u);
            ret = min(ret, low);
            if (low >= dfsn[u]) {
                if (p != -1) isCutVertex[u] = 1;
                vector<pair<int,int>> bc;
                while (st.top() != make_pair(u, v))
                    bc.push_back(st.top()), st.pop();
                bc.push_back(st.top()), st.pop();
                bcc.push_back(bc);
            }
        }
        else ret = min(ret, dfsn[v]);
    }
    if (p == -1) isCutVertex[u] = (child >= 2);
    return ret;
}

int main() {
    while (true) {
        scanf("%d", &N);
        if (!N) break;
        cnt = 0;
        bcc.clear();
        a.clear(); a.resize(100000);
        memset(dfsn, 0, sizeof(dfsn));
        memset(isCutVertex, 0, sizeof(isCutVertex));
        for (int i=0;i<N;++i) {
            scanf("%d%d", &u, &v);
            a[u].push_back(v);
            a[v].push_back(u);
        }
        for (int i=1;i<100000;++i)
            if (!dfsn[i]) dfs(i, -1);

        vector<int> way;

        for (auto &bc : bcc) {
            unordered_set<int> s;
            for (auto [u, v] : bc) {
                s.insert(u);
                s.insert(v);
            }
            int degree = 0;
            for (auto u : s)
                if (isCutVertex[u]) degree++;
            if (degree == 1) way.push_back(s.size()-1);
            if (degree == 0) {
                int x = s.size();
                int y = x-1;
                if (x % 2 == 0) x /= 2;
                if (y % 2 == 0) y /= 2;
                way.push_back(x);
                way.push_back(y);
            }
        }

        long long ans = 1;
        for (int w : way) ans *= w;

        printf("Case %d: %d %lld\n", ++tc, (int)way.size(), ans);
    }
}

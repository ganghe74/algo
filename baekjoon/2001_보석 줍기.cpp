#include <bits/stdc++.h>
using namespace std;

int n, m, k, u, v, w, gem[101];
bool c[101][1<<14];
vector<pair<int,int>> a[101];
queue<pair<int,int>> q;

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i=1;i<=k;++i) {
        scanf("%d", &u);
        gem[u] = i;
    }
    while (m--) {
        scanf("%d%d%d", &u, &v, &w);
        a[u].push_back({v, w});
        a[v].push_back({u, w});
    }
    c[0][0] = 1;
    q.push({1, 0});
    int ans = 0;
    while (!q.empty()) {
        auto [u, status] = q.front(); q.pop();
        if (u == 1) ans = max(ans, __builtin_popcount(status));
        if (gem[u]) {
            int nstatus = status | (1 << (gem[u] - 1));
            if (!c[u][nstatus]) {
                q.push({u, nstatus});
                c[u][nstatus] = 1;
            }
        }
        for (auto [v, w] : a[u]) {
            if (__builtin_popcount(status) <= w) {
                if (!c[v][status]) {
                    q.push({v, status});
                    c[v][status] = 1;
                }
            }
        }
    }
    printf("%d", ans);
}

#include <bits/stdc++.h>
using namespace std;

int N, M, u, v, cnt, group[101], cost[101], boss[101];
vector<vector<int>> d;

int main() {
    scanf("%d%d", &N, &M);
    d.assign(N+1, vector<int>(N+1, 1e9));
    for (int i=1;i<=N;++i) d[i][i] = 0;
    while (M--) {
        scanf("%d%d", &u, &v);
        d[u][v] = d[v][u] = 1;
    }
    for (int k=1;k<=N;++k) {
        for (int i=1;i<=N;++i) {
            for (int j=1;j<=N;++j) {
                if (d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    cost[0] = 1e9;
    for (int i=1;i<=N;++i) {
        if (!group[i]) group[i] = ++cnt;
        for (int j=1;j<=N;++j) {
            if (d[i][j] < 1e9) {
                group[j] = group[i];
                cost[i] = max(cost[i], d[i][j]);
            }
        }
        if (cost[i] < cost[boss[group[i]]]) boss[group[i]] = i;
    }
    vector<int> ans;
    for (int i=1;i<=cnt;++i) ans.push_back(boss[i]);
    sort(ans.begin(), ans.end());
    printf("%d\n", cnt);
    for (int x : ans) printf("%d\n", x);
}

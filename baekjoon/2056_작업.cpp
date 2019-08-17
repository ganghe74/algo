#include <bits/stdc++.h>
using namespace std;
vector<int> a[10001];
int ind[10001], cost[10001], d[10001];
int main() {
    int N, t, u, ans = 0;
    scanf("%d", &N);
    for (int v=1;v<=N;++v) {
        scanf("%d%d", &cost[v], &t);
        while (t--) {
            scanf("%d", &u);
            a[u].push_back(v);
            ind[v]++;
        }
    }
    queue<int> q;
    for (int i=1;i<=N;++i) {
        if (!ind[i]) {
            q.push(i);
            d[i] = cost[i];
            ans = max(ans, d[i]);
        }
    }
    while (!q.empty()) {
        int now = q.front(); q.pop();
        for (int next : a[now]) {
            ind[next]--;
            d[next] = max(d[next], d[now] + cost[next]);
            if (!ind[next]) {
                q.push(next);
                ans = max(ans, d[next]);
            }
        }
    }
    printf("%d", ans);
}
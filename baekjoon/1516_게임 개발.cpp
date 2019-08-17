#include <bits/stdc++.h>
using namespace std;
vector<int> a[501];
int ind[501], cost[501], d[501];
int main() {
    int N, u;
    scanf("%d", &N);
    for (int v=1;v<=N;++v) {
        scanf("%d", &cost[v]);
        while (true) {
            scanf("%d", &u);
            if (u == -1) break;
            a[u].push_back(v);
            ind[v]++;
        }
    }
    queue<int> q;
    for (int v=1;v<=N;++v) {
        if (!ind[v]) {
            q.push(v);
            d[v] = cost[v];
        }
    }
    while (!q.empty()) {
        int now = q.front(); q.pop();
        for (int next : a[now]) {
            ind[next]--;
            d[next] = max(d[next], d[now] + cost[next]);
            if (!ind[next]) {
                q.push(next);
            }
        }
    }
    for (int i=1;i<=N;++i) printf("%d\n", d[i]);
}
#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int N, p[100001], S[100002];
lint M, w[100002];
priority_queue<pair<int,int>> pq;

int Find(int u) {
    if (u == p[u]) return u;
    return p[u] = Find(p[u]);
}

void Union(int u, int v) {
    u = Find(u); v = Find(v);
    if (u == v || !u || !v) return;
    w[v] += w[u];
    p[u] = v;
}

int main() {
    scanf("%d%lld", &N, &M);
    for (int i=1;i<=N;++i) {
        scanf("%lld%d", &w[i], &S[i]);
        pq.push({-S[i], i});
        p[i] = i;
    }

    while (!pq.empty()) {
        int u = pq.top().second; pq.pop();
        if (S[u-1] <= S[u]) Union(u-1, u);
        if (S[u+1] <= S[u]) Union(u+1, u);
        if (w[Find(u)] >= M) {
            printf("%d", S[u]);
            break;
        }
    }
}

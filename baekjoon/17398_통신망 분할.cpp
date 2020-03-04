#include <bits/stdc++.h>
using namespace std;

int N, M, Q, X, Y, p[100001], w[100001];
bool c[100000];
vector<pair<int,int>> edges;
vector<int> op;

int Find(int u) {
    if (u == p[u]) return u;
    return p[u] = Find(p[u]);
}

void Union(int u, int v) {
    u = Find(u); v = Find(v);
    if (u == v) return;
    w[v] += w[u];
    p[u] = v;
}

int main() {
    scanf("%d%d%d", &N, &M, &Q);
    for (int i=1;i<=N;++i) p[i] = i, w[i] = 1;
    for (int i=0;i<M;++i) {
        scanf("%d%d", &X, &Y);
        edges.push_back({X, Y});
    }
    for (int i=0;i<Q;++i) {
        scanf("%d", &X);
        op.push_back(X-1);
        c[X-1] = 1;
    }
    for (int i=0;i<M;++i)
        if (!c[i]) Union(edges[i].first, edges[i].second);

    long long ans = 0;
    for (int i=Q-1;i>=0;--i) {
        tie(X, Y) = edges[op[i]];
        X = Find(X); Y = Find(Y);
        if (X != Y) {
            ans += 1LL * w[X] * w[Y];
            Union(X, Y);
        }
    }
    printf("%lld", ans);
}

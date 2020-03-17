#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
using lint = long long;
constexpr int IS=1<<22;
char I[IS], *J=I;

int N, M, D, E, u, v, w, h[100001];
vector<pair<int,int>> a[100001];

vector<lint> dijkstra(int src) {
    vector<lint> d(N+1, 1e18);
    d[src] = 0;
    priority_queue<pair<lint,int>> pq;
    pq.push({0, src});
    while (!pq.empty()) {
        auto [dist, u] = pq.top(); pq.pop();
        if (-dist > d[u]) continue;
        for (auto [v, w] : a[u]) {
            if (h[u] < h[v]) {
                lint nextDist = -dist + w;
                if (nextDist < d[v]) {
                    d[v] = nextDist;
                    pq.push({-d[v], v});
                }
            }
        }
    }
    return d;
}

int main() {
    syscall(0,0,I,IS);
    auto daer=[&]{if(J>=I+IS-16){char*p=I;do*p++=*J++;while(J!=I+IS);syscall(0,0,p,I+IS-p);J=I;}};
    auto getu=[&]{daer();int x=0;do x=x*10+*J-'0';while(*++J>='0');++J;return x;};
    N = getu(); M = getu(); D = getu(); E = getu();
    for (int i=1;i<=N;++i) h[i] = getu();
    while (M--) {
        u = getu(); v = getu(); w = getu();
        a[u].push_back({v, w});
        a[v].push_back({u, w});
    }
    vector<lint> d1 = dijkstra(1);
    vector<lint> d2 = dijkstra(N);
    lint ans = -1e18;
    for (int i=2;i<N;++i) {
        if (d1[i] == 1e18 || d2[i] == 1e18) continue;
        lint val = h[i] * E - (d1[i]+d2[i]) * D;
        ans = max(ans, val);
    }
    if (ans == -1e18) puts("Impossible");
    else printf("%lld", ans);
}

#include <bits/stdc++.h>
using namespace std;
vector<tuple<int,int,int>> a;
int d[501];
int main() {
    int N, M, u, v, w;
    scanf("%d%d", &N, &M);
    for (int i=0;i<M;++i) {
        scanf("%d%d%d", &u, &v, &w);
        a.push_back({u,v,w});
    }
    fill(d, d+501, INT_MAX);
    d[1] = 0;
    bool ncycle = 0;
    for (int i=1;i<=N;++i) {
        for (int j=0;j<M;++j) {
            tie(u,v,w) = a[j];
            if (d[u] != INT_MAX && d[u]+w < d[v]) {
                d[v] = d[u]+w;
                if (i == N) ncycle = true;
            }
        }
    }
    if (ncycle) puts("-1");
    else {
        for (int i=2;i<=N;++i) {
            if (d[i] == INT_MAX) puts("-1");
            else printf("%d\n", d[i]);
        }
    }
}
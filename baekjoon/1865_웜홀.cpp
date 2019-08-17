#include <bits/stdc++.h>
using namespace std;
int main() {
    int TC, N, M, W, u, v, w;
    scanf("%d", &TC);
    while (TC--) {
        scanf("%d%d%d", &N, &M, &W);
        vector<tuple<int,int,int>> a;
        vector<int> d(N+1, INT_MAX);
        while (M--) {
            scanf("%d%d%d", &u, &v, &w);
            a.push_back({u,v,w});
            a.push_back({v,u,w});
        }
        while (W--) {
            scanf("%d%d%d", &u, &v, &w);
            a.push_back({u,v,-w});
        }
        d[1] = 0;
        bool ncycle = false;
        for (int i=1;i<=N;++i) {
            for (int j=0;j<a.size();++j) {
                tie(u,v,w) = a[j];
                if (d[u] != INT_MAX && d[u]+w < d[v]) {
                    d[v] = d[u]+w;
                    if (i == N) ncycle = true;
                }
            }
        }
        if (ncycle) puts("YES");
        else puts("NO");
    }
}
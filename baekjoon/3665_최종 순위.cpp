#include <bits/stdc++.h>
using namespace std;
int main() {
    int T, N, M, u, v;
    scanf("%d", &T);
    while (T--) {
        bool a[501][501];
        int rank[501], ind[501];
        memset(a, 0, sizeof(a));
        memset(rank, 0, sizeof(rank));
        memset(ind, 0, sizeof(ind));
        scanf("%d", &N);
        for (int i=0;i<N;++i) {
            scanf("%d", &rank[i]);
            for (int j=0;j<i;++j) {
                a[rank[j]][rank[i]] = 1;
                ind[rank[i]]++;
            }
        }
        scanf("%d", &M);
        while (M--) {
            scanf("%d%d", &u, &v);
            if (a[v][u]) swap(u, v);
            a[u][v] = 0;
            a[v][u] = 1;
            ind[v]--;
            ind[u]++;
        }
        queue<int> q, ans;
        for (int i=1;i<=N;++i)
            if (!ind[i]) q.push(i);
        if (q.size() > 1) puts("?");
        else {
            while (!q.empty()) {
                int now = q.front(); q.pop();
                ans.push(now);
                for (int next=1;next<=N;++next) {
                    if (a[now][next]) {
                        --ind[next];
                        if (!ind[next]) {
                            q.push(next);
                        }
                    }
                }
            }
            if (ans.size() != N) puts("IMPOSSIBLE");
            else {
                while (!ans.empty()) {
                    printf("%d ", ans.front()); ans.pop();
                }
                puts("");
            }
        }
    }
}
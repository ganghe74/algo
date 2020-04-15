#include <bits/stdc++.h>
using namespace std;

int P, C, u, v, cnt, component, dfsn[10000], bcc[10000];
vector<vector<int>> a;

int dfs(int u, bool root) {
    int ret = dfsn[u] = ++cnt;
    int child = 0;
    for (int v : a[u]) {
        if (!dfsn[v]) {
            child++;
            int low = dfs(v, 0);
            ret = min(ret, low);
            if (!root && low >= dfsn[u]) bcc[u]++;
        }
        else ret = min(ret, dfsn[v]);
    }
    if (root) {
        if (child >= 2) bcc[u] = child;
        else bcc[u] = child;
    }
    else {
        if (bcc[u]) bcc[u]++;
        else bcc[u] = 1;
    }
    return ret;
}

int main() {
    while (true) {
        scanf("%d%d", &P, &C);
        if (!P && !C) break;
        cnt = component = 0;
        a.clear(); a.resize(P);
        fill(dfsn, dfsn+P, 0);
        fill(bcc, bcc+P, 0);
        while (C--) {
            scanf("%d%d", &u, &v);
            a[u].push_back(v);
            a[v].push_back(u);
        }
        for (int i=0;i<P;++i)
            if (!dfsn[i]) component++, dfs(i, 1);
        int m = 0;
        for (int i=0;i<P;++i) m = max(m, bcc[i]);
        printf("%d\n", component+m-1);
    }
}

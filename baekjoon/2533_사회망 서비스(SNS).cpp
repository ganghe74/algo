#include <bits/stdc++.h>
using namespace std;

int n, u, v, d[2][1000000];

vector<vector<int>> a;

int solve(int u, int p, bool p_ea) {
    int &ret = d[p_ea][u];
    if (ret != -1) return ret;
    ret = 1;
    for (int v : a[u])
        if (v != p) ret += solve(v, u, true);
    if (p_ea) {
        int t = 0;
        for (int v : a[u])
            if (v != p) t += solve(v, u, false);
        ret = min(ret, t);
    }
    return ret;
}

int main() {
    scanf("%d", &n);
    a.resize(n);
    for (int i=1;i<n;++i) {
        scanf("%d%d", &u, &v);
        u--; v--;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    memset(d, -1, sizeof(d));
    printf("%d", solve(0, -1, true));
}

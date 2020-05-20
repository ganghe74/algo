#include <bits/stdc++.h>
using namespace std;

int n, u, v, a[10000], d[10000][4];
vector<int> adj[10000];

int solve(int u, int p, bool e, bool pe) {
    int &ret = d[u][e*2+pe];
    if (ret != -1) return ret;
    if (e) {
        ret = a[u];
        for (int v : adj[u])
            if (v != p) ret += solve(v, u, 0, 1);
    }
    else {
        ret = 0;
        int minloss = 2e9;
        for (int v : adj[u]) {
            if (v != p) {
                ret += max(solve(v, u, 1, 0), solve(v, u, 0, 0));
                minloss = min(minloss, solve(v, u, 0, 0) - solve(v, u, 1, 0));
            }
        }
        if (minloss == 2e9) return 0;
        if (!pe) ret -= max(minloss, 0);
    }
    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i=0;i<n;++i)
        scanf("%d", &a[i]);
    for (int i=1;i<n;++i) {
        scanf("%d%d", &u, &v);
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(d, -1, sizeof(d));
    printf("%d\n", max(solve(0, -1, 1, 0), solve(0, -1, 0, 0)));
}

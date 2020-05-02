#include <bits/stdc++.h>
using namespace std;

int n, u, v, a[200000], d[200000];
vector<int> adj[200000];

vector<int> lis = {int(-1e9)};

void dfs(int u) {
    bool inserted = (a[u] > lis.back());
    int idx, replaced;
    if (inserted) {
        lis.push_back(a[u]);
    }
    else {
        auto it = lower_bound(lis.begin(), lis.end(), a[u]);
        idx = it - lis.begin();
        replaced = lis[idx];
        lis[idx] = a[u];
    }

    d[u] = lis.size() - 1;

    for (int v : adj[u]) {
        if (!d[v]) dfs(v);
    }
    if (inserted) lis.pop_back();
    else lis[idx] = replaced;
}

int main() {
    scanf("%d", &n);
    for (int i=0;i<n;++i) scanf("%d", &a[i]);
    for (int i=1;i<n;++i) {
        scanf("%d%d", &u, &v);
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0);
    for (int i=0;i<n;++i)
        printf("%d\n" ,d[i]);
}

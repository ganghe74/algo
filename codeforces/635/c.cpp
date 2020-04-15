#include <bits/stdc++.h>
using namespace std;

int n, k, u, v, depth[200001], p[200001], w[200001], loss[200001];
vector<int> a[200001];
priority_queue<pair<int,int>> pq;

long long ans;

void dfs(int u, int parent) {
    p[u] = parent;
    depth[u] = depth[parent] + 1;
    for (int v : a[u]) {
        if (!depth[v]) {
            dfs(v, u);
            w[u]++;
        }
    }
    if (!w[u]) {
        pq.push({depth[u]-1, u});
    }
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i=1;i<n;++i) {
        scanf("%d%d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1, 0);

    while (k--) {
        auto [earn, u] = pq.top(); pq.pop();
        ans += earn;
        int parent = p[u];
        w[parent]--;
        loss[parent] += loss[u] + 1;
        if (!w[parent]) {
            pq.push({depth[parent] - loss[parent] - 1, parent});
        }
    }

    printf("%lld", ans);
}
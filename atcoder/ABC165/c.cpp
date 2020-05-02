#include <bits/stdc++.h>
using namespace std;

int n, m, q, ans, a[10];
vector<tuple<int,int,int,int>> info;

void dfs(int idx, int lo) {
    if (idx == n) {
        int score = 0;
        for (auto [x, y, z, w] : info)
            if (a[y] - a[x] == z) score += w;
        ans = max(ans, score);
        return;
    }
    for (int i=lo;i<=m;++i) {
        a[idx] = i;
        dfs(idx+1, i);
    }
}

int main() {
    a[0] = 1;
    scanf("%d%d%d", &n, &m, &q);
    for (int i=0;i<q;++i) {
        int x, y, z, w;
        scanf("%d%d%d%d", &x, &y, &z, &w);
        info.push_back({x-1, y-1, z, w});
    }
    dfs(0, 1);
    printf("%d", ans);
}

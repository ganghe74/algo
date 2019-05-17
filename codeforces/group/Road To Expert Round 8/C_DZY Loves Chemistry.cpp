#include <bits/stdc++.h>
using namespace std;

vector<int> a[101];
bool c[101];
int dfs(int now) {
    c[now] = 1;
    int ret = 1;
    for (int next : a[now]) {
        if (!c[next]) ret += dfs(next);
    }
    return ret;
}

int main() {
    long long danger = 1;
    int n, m, x, y;
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for (int i=1;i<=n;++i) {
        if (!c[i]) danger *= (1LL << (dfs(i)-1));
    }
    printf("%lld", danger);
}
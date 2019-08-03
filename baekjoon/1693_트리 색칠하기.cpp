#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> a(100001);
int d[100001][19];
bool visited[100001];

int solve(int now, int color) {
    int &ret = d[now][color];
    if (ret > 0) return ret;
    ret = color;
    visited[now] = 1;
    for (int next : a[now]) {
        if (visited[next]) continue;
        int m = 1e+9;
        for (int i=1;i<=18;++i) {
            if (i == color) continue;
            m = min(m, solve(next, i));
        }
        ret += m;
    }
    visited[now] = 0;
    return ret;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i=1;i<n;++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    a[0].push_back(1);
    printf("%d", solve(0, 0));
}
#include <bits/stdc++.h>
using namespace std;

int n, u, v, w[10001], d[10001][2];
vector<int> a[10001];
vector<pair<int,int>> p[10001][2];
bool c[10001];

int solve(int u, bool used) {
    int &ret = d[u][used];
    if (ret) return ret;
    c[u] = 1;
    for (int v : a[u]) {
        if (!c[v]) {
            if (used) {
                ret += solve(v, 0);
                p[u][used].push_back({v, 0});
            }
            else {
                if (solve(v, 0) > solve(v, 1)) {
                    ret += solve(v, 0);
                    p[u][used].push_back({v, 0});
                }
                else {
                    ret += solve(v, 1);
                    p[u][used].push_back({v, 1});
                }
            }
        }
    }
    c[u] = 0;
    if (used) ret += w[u];
    return ret;
}

vector<int> ans;
void f(int u, bool used) {
    for (auto [v, s] : p[u][used]) {
        if (s) ans.push_back(v);
        f(v, s);
    }
}

int main() {
    scanf("%d", &n);
    for (int i=1;i<=n;++i) scanf("%d", &w[i]);
    for (int i=1;i<n;++i) {
        scanf("%d%d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    a[0].push_back(1);
    printf("%d\n", solve(0, 0));
    f(0, 0);
    sort(ans.begin(), ans.end());
    for (int u : ans) printf("%d ", u);
}

#include <bits/stdc++.h>
using namespace std;

int T, F, p[100002], w[100002];
unordered_map<string, int> m;
string a, b;

int Find(int u) {
    if (u == p[u]) return u;
    return p[u] = Find(p[u]);
}

void Union(int u, int v) {
    u = Find(u); v = Find(v);
    if (u == v) return;
    w[v] += w[u];
    p[u] = v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> F;
        for (int i=1;i<=F+1;++i) p[i] = i, w[i] = 1;
        int num = 1;
        m.clear();
        while (F--) {
            cin >> a >> b;
            if (!m[a]) m[a] = num++;
            if (!m[b]) m[b] = num++;
            Union(m[a], m[b]);
            cout << w[Find(m[a])] << '\n';
        }
    }
}

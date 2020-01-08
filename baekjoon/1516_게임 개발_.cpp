#include <bits/stdc++.h>
using namespace std;

int N, u, v;
vector<int> a[501];
int ind[501], t[501], d[501];

int main() {
    scanf("%d", &N);
    for (v=1;v<=N;++v) {
        scanf("%d", &t[v]);
        while (true) {
            scanf("%d", &u);
            if (u == -1) break;
            a[u].push_back(v);
            ind[v]++;
        }
    }
    queue<int> q;
    for (v=1;v<=N;++v) {
        if (!ind[v]) {
            q.push(v);
            d[v] = t[v];
        }
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : a[u]) {
            d[v] = max(d[v], d[u]+t[v]);
            if (!--ind[v]) q.push(v);
        }
    }
    for (v=1;v<=N;++v) printf("%d\n", d[v]);
}
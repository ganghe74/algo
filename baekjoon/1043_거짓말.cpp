#include <bits/stdc++.h>
using namespace std;

int N, M, C, x;
vector<int> know;
vector<int> party[50];
bool a[51][51], c[51];

void dfs(int u) {
    c[u] = 1;
    for (int v=1;v<=N;++v)
        if (a[u][v] && !c[v]) dfs(v);
}

int main() {
    scanf("%d%d%d", &N, &M, &C);
    know.resize(C);
    for (int i=0;i<C;++i) scanf("%d", &know[i]);
    for (int i=0;i<M;++i) {
        scanf("%d", &C);
        party[i].resize(C);
        for (int j=0;j<C;++j) scanf("%d", &party[i][j]);
        for (int j=0;j<C;++j) {
            for (int k=0;k<C;++k) {
                int u = party[i][j], v = party[i][k];
                a[u][v] = a[v][u] = 1;
            }
        }
    }

    for (int u : know) dfs(u);

    int ans = 0;
    for (int i=0;i<M;++i) {
        bool ok = true;
        for (int p : party[i]) {
            if (c[p]) {
                ok = false;
                break;
            }
        }
        if (ok) ans++;
    }
    printf("%d", ans);
}

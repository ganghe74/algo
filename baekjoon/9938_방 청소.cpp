#include <bits/stdc++.h>
using namespace std;

int N, L, a, b, p[300001];
bool c[300001];

int Find(int u) {
    if (u == p[u]) return u;
    return p[u] = Find(p[u]);
}

void Union(int u, int v) {
    u = Find(u); v = Find(v);
    if (c[u]) p[u] = v;
    else p[v] = u;
}

int main() {
    scanf("%d%d", &N, &L);
    iota(p, p+L+1, 0);

    for (int i=0;i<N;++i) {
        scanf("%d%d", &a, &b);
        if (!c[a]) c[a] = 1;
        else if (!c[b]) c[b] = 1;
        else if (!c[Find(a)]) c[Find(a)] = 1;
        else if (!c[Find(b)]) c[Find(b)] = 1;
        else {
            puts("SMECE");
            continue;
        }
        Union(a, b);
        puts("LADICA");
    }
}

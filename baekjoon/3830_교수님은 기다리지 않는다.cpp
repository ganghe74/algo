#include <bits/stdc++.h>
using namespace std;

int N, M, a, b, c, p[100001], w[100001];
char op;

int Find(int u) {
    if (!p[u]) return u;
    int pp = p[u];
    p[u] = Find(p[u]);
    w[u] += w[pp];
    return p[u];
}

int Weight(int u) {
    Find(u);
    return w[u];
}

void Union(int u, int v, int weight) {
    if (Find(u) == Find(v)) return;
    weight += Weight(u);
    weight -= Weight(v);
    u = Find(u); v = Find(v);
    p[v] = u;
    w[v] += weight;
}

int main() {
    while (true) {
        scanf("%d%d", &N, &M);
        if (!N && !M) break;
        memset(p, 0, sizeof(p));
        memset(w, 0, sizeof(w));
        while (M--) {
            scanf(" %c %d %d", &op, &a, &b);
            if (op == '!') {
                scanf("%d", &c);
                Union(a, b, c);
            }
            else {
                if (Find(a) == Find(b)) printf("%d\n", Weight(b) - Weight(a));
                else puts("UNKNOWN");
            }
        }
    }
}

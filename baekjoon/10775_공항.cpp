#include <bits/stdc++.h>
using namespace std;

int G, P, cnt, n, p[100001];

int Find(int u) {
    if (u == p[u]) return u;
    return p[u] = Find(p[u]);
}

int main() {
    scanf("%d%d", &G, &P);
    for (int i=0;i<=G;++i) p[i] = i;
    while (cnt < P) {
        scanf("%d", &n);
        n = Find(n);
        if (!n) break;
        p[n] = n-1;
        cnt++;
    }
    printf("%d", cnt);
}

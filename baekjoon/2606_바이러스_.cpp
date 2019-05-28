#include <bits/stdc++.h>
using namespace std;

int p[101];
int Find(int x) {
    if (x == p[x]) return x;
    return p[x] = Find(p[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    p[x] = y;
}

int main() {
    for (int i=0;i<=100;++i) p[i] = i;
    int n, m, a, b, ans = 0;
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d", &a, &b);
        Union(a, b);
    }
    for (int i=2;i<=100;++i) {
        if (Find(1) == Find(i)) ans++;
    }
    printf("%d", ans);
}
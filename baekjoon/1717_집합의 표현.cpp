#include <bits/stdc++.h>
using namespace std;

int p[1000001];

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
    for (int i=0;i<=1000000;++i) p[i] = i;
    int n, m;
    scanf("%d%d", &n, &m);
    while (m--) {
        int op, a, b;
        scanf("%d%d%d", &op, &a, &b);
        if (op == 0) {
            Union(a, b);
        }
        else {
            if (Find(a) == Find(b)) puts("YES");
            else puts("NO");
        }
    }
}
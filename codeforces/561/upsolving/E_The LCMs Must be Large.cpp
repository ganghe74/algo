#include <bits/stdc++.h>
using namespace std;
int m, n, si, idx;
bool c[50][10001];
bool check(int d1, int d2) {
    for (int i=1;i<=n;++i) {
        if (c[d1][i] == 1 && c[d1][i] == c[d2][i]) return true;
    }
    return false;
}
int main() {
    scanf("%d%d", &m, &n);
    for (int d=0;d<m;++d) {
        scanf("%d", &si);
        while (si--) {
            scanf("%d", &idx);
            c[d][idx] = 1;
        }
    }
    bool ok = true;
    for (int i=0;i<m;++i) {
        for (int j=i+1;j<m;++j) {
            if (!check(i, j)) ok = false;
        }
    }
    if (ok) puts("possible");
    else puts("impossible");
}
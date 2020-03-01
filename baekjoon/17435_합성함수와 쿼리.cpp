#include <bits/stdc++.h>
using namespace std;

int m, Q, n, x, f[19][200001];

int main() {
    scanf("%d", &m);
    for (int i=1;i<=m;++i) scanf("%d", &f[0][i]);
    for (int i=1;i<19;++i)
        for (int j=1;j<=m;++j)
            f[i][j] = f[i-1][f[i-1][j]];
    scanf("%d", &Q);
    while (Q--) {
        scanf("%d%d", &n, &x);
        for (int i=18;i>=0;--i) {
            if (n >= 1<<i) {
                x = f[i][x];
                n -= 1<<i;
            }
        }
        printf("%d\n", x);
    }
}

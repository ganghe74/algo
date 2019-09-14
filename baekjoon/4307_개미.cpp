#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, l, n, x, m, M;
    scanf("%d", &T);
    while (T--) {
        M = m = 0;
        scanf("%d%d", &l, &n);
        while (n--) {
            scanf("%d", &x);
            M = max({M, x, l-x});
            m = max({m, min(x, l-x)});
        }
        printf("%d %d\n", m, M);
    }
}
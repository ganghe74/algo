#include <bits/stdc++.h>
using namespace std;

int N, M, d[101][101];

int bino(int n, int r) {
    if (n == 1) return 1;
    if (r == 0 || r == n) return 1;
    if (d[n][r]) return d[n][r];
    return bino(n-1,r-1) + bino(n-1,r);
}

int main() {
    scanf("%d%d", &N, &M);
    int ans = 0;
    if (N > 1) ans += bino(N,2);
    if (M > 1) ans += bino(M,2);
    printf("%d", ans);
}

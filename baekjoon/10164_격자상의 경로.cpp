#include <bits/stdc++.h>
using namespace std;

int N, M, K, d[30][30];

int bino(int n, int r) {
    if (r < 0 || r > n) return 0;
    if (d[n][r]) return d[n][r];
    return d[n][r] = bino(n-1, r-1) + bino(n-1, r);
}

int main() {
    d[0][0] = 1;
    for (int i=2;i<=15;++i)
    scanf("%d%d%d", &N, &M, &K);
    if (!K) K = 1;
    int r = (K-1) / M + 1, c = (K-1) % M + 1;
    printf("%d", bino(r+c-2, r-1) * bino(N+M-r-c, M-c));
}

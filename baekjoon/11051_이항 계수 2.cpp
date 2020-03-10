#include <bits/stdc++.h>
using namespace std;

int N, K, d[1001][1001];

int bino(int n, int r) {
    if (r < 0 || r > n) return 0;
    if (d[n][r]) return d[n][r];
    return d[n][r] = (bino(n-1, r-1) + bino(n-1, r)) % 10007;
}

int main() {
    d[0][0] = 1;
    scanf("%d%d", &N, &K);
    printf("%d", bino(N, K));
}
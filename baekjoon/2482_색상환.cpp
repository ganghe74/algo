#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9+3;
int N, K, d[1001][1001];

int solve(int n, int k) {
    if (k > n) return 0;
    if (k <= 1) return n;
    if (d[n][k] != -1) return d[n][k];
    return d[n][k] = (solve(n-2, k-1) + solve(n-1, k)) % MOD;
}

int main() {
    memset(d, -1, sizeof(d));
    scanf("%d%d", &N, &K);
    printf("%d", (solve(N-3, K-1) + solve(N-1, K)) % MOD);
}

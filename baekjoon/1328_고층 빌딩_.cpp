#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
long long d[105][105][105];
int main() {
    int N, L, R;
    scanf("%d%d%d", &N, &L, &R);
    d[1][1][1] = 1;
    for (int i=1;i<=N;++i) {
        for (int j=1;j<=L;++j) {
            for (int k=1;k<=R;++k) {
                d[i][j][k] %= MOD;
                d[i+1][j+1][k] += d[i][j][k];
                d[i+1][j][k+1] += d[i][j][k];
                d[i+1][j][k] += d[i][j][k] * (i-1);
            }
        }
    }
    printf("%lld", d[N][L][R]);
}
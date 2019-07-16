#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
long long d[101][101][101];
int main() {
    int N, L, R;
    scanf("%d%d%d", &N, &L, &R);
    d[1][1][1] = 1;
    for (int i=2;i<=N;++i) {
        for (int j=1;j<=L;++j) {
            for (int k=1;k<=R;++k) {
                d[i][j][k] = d[i-1][j-1][k] + d[i-1][j][k-1] + d[i-1][j][k] * (i-2);
                d[i][j][k] %= MOD;
            }
        }
    }
    printf("%lld", d[N][L][R]);
}
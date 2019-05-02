#include <iostream>
using namespace std;
const int MOD = 1e9+9;
int d[100001][3];
int main() {
    d[0][0] = 1; d[1][0] = 1; d[2][1] = 1;
    for (int i=3;i<=100000;++i) {
        d[i][0] = (d[i-1][1] + d[i-1][2]) % MOD;
        d[i][1] = (d[i-2][0] + d[i-2][2]) % MOD;
        d[i][2] = (d[i-3][0] + d[i-3][1]) % MOD;
    }
    int T, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        printf("%d\n", ((d[n][0] + d[n][1]) % MOD + d[n][2]) % MOD);
    }
}
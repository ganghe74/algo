#include <iostream>
#include <cstring>
using namespace std;
const int MOD = 1e9+9;
int d[1001][1001];
int solve(int n, int m) {
    if (n <= 0 || m <= 0) return 0;
    int &ret = d[n][m];
    if (ret > -1) return ret;
    ret = ((solve(n-1, m-1) + solve(n-2, m-1)) % MOD + solve(n-3, m-1)) % MOD;
    return ret;
}
int main() {
    memset(d, -1, sizeof(d));
    d[1][1] = 1; d[2][1] = 1; d[3][1] = 1;
    int T, n, m;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        printf("%d\n", solve(n, m));
    }
}
#include <iostream>
using namespace std;
const int MOD = 1e9+9;
int d[100001] = {1,1,2};
int main() {
    for (int i=3;i<=100000;++i) {
        d[i] = ((d[i-1] + d[i-2]) % MOD + d[i-3]) % MOD;
    }
    int T, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        if (n % 2) printf("%d\n", (d[n/2] + d[n/2-1]) % MOD);
        else printf("%d\n", (d[n/2] + d[n/2-1]) % MOD);
    }
}
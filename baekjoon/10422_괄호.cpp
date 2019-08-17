#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
const int MOD = 1e9+7;

lint d[5001];
int main() {
    d[0] = 1;
    for (int i=2;i<=5000;i+=2) {
        for (int j=0;j<i;j+=2) {
            d[i] += d[j] * d[i-j-2];
            d[i] %= MOD;
        }
    }
    int T, L;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &L);
        printf("%lld\n", d[L]);
    }
}
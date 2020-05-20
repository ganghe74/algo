#include <bits/stdc++.h>
using namespace std;
using lint = long long;

const lint MOD = 1e9+7;
int M, N, K;
lint fac[4000001], facinv[4000001];

lint powll(lint x, lint y) {
    if (y == 1) return x;
    if (y % 2 == 1) return x * powll(x, y-1) % MOD;
    lint z = powll(x, y/2);
    return z * z % MOD;
}

int main() {
    fac[0] = 1;
    for (int i=1;i<=4000000;++i)
        fac[i] = (fac[i-1] * i) % MOD;
    facinv[4000000] = powll(fac[4000000], MOD-2);
    for (int i=3999999;i>=1;--i)
        facinv[i] = (facinv[i+1] * (i+1)) % MOD;

    scanf("%d", &M);
    while (M--) {
        scanf("%d%d", &N, &K);
        if (K == 0 || K == N) puts("1");
        else printf("%lld\n", (((fac[N] * facinv[K]) % MOD) * facinv[N-K]) % MOD);
    }
}

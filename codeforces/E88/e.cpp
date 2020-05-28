#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint mod = 998244353;

lint n, k;
lint fact[500001], finv[500001];

lint fastpow(lint a, lint b) {
    if (b == 1) return a;
    if (b % 2 == 1) return a * fastpow(a, b-1) % mod;
    lint t = fastpow(a, b/2);
    return t * t % mod;
}

int main() {
    fact[0] = 1;
    for (int i=1;i<=500000;++i)
        fact[i] = (fact[i-1] * i) % mod;
    finv[500000] = fastpow(fact[500000], mod-2);
    for (int i=499999;i>=1;--i)
        finv[i] = (finv[i+1] * (i+1)) % mod;

    cin >> n >> k;
    lint ans = 0;
    for (lint a1=1;n/a1>=k;a1++) {
        lint m = n / a1;
        lint N = m-1;
        lint R = k-1;
        lint nCr = ((fact[N] * finv[R]) % mod * finv[N-R]) % mod;
        if (!nCr) nCr++;
        ans += nCr;
        ans %= mod;
    }
    cout << ans;
}

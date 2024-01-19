#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint MOD = 998244353;

lint N, M;

lint fastpow(lint a, lint b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    if (b % 2) return (fastpow(a, b-1) * a) % MOD;
    lint t = fastpow(a, b/2);
    return t * t % MOD;
}

lint inv(lint a) {
    return fastpow(a, MOD-2);
}

lint B[200001];
lint binom(lint k) {
    lint &ret = B[k];
    if (ret) return ret;
    ret = binom(k-1) * (N-k+1) % MOD;
    ret = ret * inv(k) % MOD;
    return ret;
}



int main() {
    cin >> N >> M;
    B[0] = B[N] = 1;
    lint x = binom(M) * fastpow(25, N-M) % MOD;
    lint ans = x * x % MOD;
    for (int i=M+1;i<=N;++i) {
        lint t = binom(i) * fastpow(25, N-i) % MOD;
        t = t * x * 2 % MOD;
        ans = (ans + t) % MOD;
    }
    cout << ans;
}
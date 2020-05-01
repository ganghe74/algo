#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint p = 998244353;
 
lint fastpow(lint a, lint b) {
    if (b == 0) return 1;
    if (b % 2 == 1) return a * fastpow(a, b-1) % p;
    lint t = fastpow(a, b/2);
    return t * t % p;
}
 
lint d[200001];
lint factorial(lint x) {
    if (!x) return 1;
    if (d[x]) return d[x];
    return d[x] = x * factorial(x-1) % p;
}
 
lint binomial(lint n, lint r) {
    if (r < 0 || r > n) return 0;
    return factorial(n) * fastpow(factorial(r), p-2) % p * fastpow(factorial(n-r), p-2) % p;
}
 
int main() {
    lint n, k;
    cin >> n >> k;
    lint c = n - k;
    lint ans = 0;
    for (lint i=0;i<=c;++i)
        ans = (ans + (i%2 ? -1 : 1) * binomial(c, i) * fastpow(c-i, n) + p) % p;
    ans = ans * binomial(n, c) % p;
    if (k) ans = ans * 2 % p;
    cout << ans;
}


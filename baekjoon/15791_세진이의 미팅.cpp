#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint p = 1e9+7;
lint fact[1000001];

lint fastpow(lint a, lint b) {
    if (!b) return 1;
    if (b%2) return a * fastpow(a,b-1) % p;
    lint t = fastpow(a, b/2);
    return t * t % p;
}

int main() {
    fact[0] = 1;
    for (int i=1;i<=1000000;++i) fact[i] = fact[i-1] * i % p;
    lint n, m;
    cin >> n >> m;
    cout << fact[n] * fastpow(fact[m], p-2) % p * fastpow(fact[n-m], p-2) % p;
}

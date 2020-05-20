#include <bits/stdc++.h>
using namespace std;
using lint = long long;

const lint p = 1e9+7;

lint mypow(lint a, lint b) {
    if (b == 0) return 1;
    if (b % 2 == 1) return a * mypow(a, b-1) % p;
    lint t = mypow(a, b/2);
    return t * t % p;
}
lint inv(lint a) { return mypow(a, p-2); }

lint fact[1000001];

int main() {
    fact[0] = 1;
    for (int i=1;i<=1000000;++i)
        fact[i] = fact[i-1] * i % p;
    lint n, r;
    cin >> n >> r;
    cout << fact[n] * inv(fact[r]) % p * inv(fact[n-r]) % p;
}

#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint p = 1e9+7;

lint fastpow(lint a, lint b) {
    if (!b) return 1;
    if (b%2) return a * fastpow(a,b-1) % p;
    lint t = fastpow(a,b/2);
    return t * t % p;
}

int main() {
    lint m, n, s, ans = 0;
    scanf("%lld", &m);
    while (m--) {
        scanf("%lld%lld", &n, &s);
        ans = (ans + s * fastpow(n, p-2)) % p;
    }
    printf("%lld", ans);
}

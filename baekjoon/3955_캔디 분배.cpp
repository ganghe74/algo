#include <bits/stdc++.h>
using namespace std;
using lint = long long;

tuple<lint,lint,lint> exgcd(lint a, lint b) {
    if (!b)
        return {a, 1, 0};
    int g, x, y;
    tie(g, x, y) = exgcd(b, a%b);
    return {g, y, x-y*(a/b)};
}

int main() {
    lint t, K ,C;
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld%lld", &K, &C);
        lint g, x, y;
        tie(g, x, y) = exgcd(C, K);
        while (C*x <= K) x += K;
        if (x > 1000000000 || g != 1) puts("IMPOSSIBLE");
        else printf("%lld\n", x);
    }
}

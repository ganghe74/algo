#include <bits/stdc++.h>
using namespace std;
using lint = long long;

tuple<lint,lint,lint> exgcd(lint a, lint b) {
    if (!b) return {a, 1, 0};
    auto [g, x, y] = exgcd(b, a%b);
    return {g, y, x-y*(a/b)};
}

int main() {
    lint n, a;
    scanf("%lld%lld", &n, &a);
    auto [g, x, y] = exgcd(a, n);
    x = (x + n) % n;
    if (g != 1) x = -1;
    printf("%lld %lld", n-a, x);
}

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

tuple<lint,lint,lint> exgcd(lint a, lint b) {
    if (!b) return {a, 1, 0};
    auto [d, x, y] = exgcd(b, a%b);
    return {d, y, x-y*(a/b)};
}

int main() {
    lint t, r, s, q;
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld%lld%lld", &r, &s, &q);
        s = -s;
        auto [d, x, y] = exgcd(r, s);
        y = ((-y*q/d)%(r/d) + (r/d))%(r/d);
        x = (q + s*y)/r;
        if (x < 1 || y< 1) {
            x += s / d;
            y += r / d;
        }
        printf("%lld %lld\n", x, y);
    }
}

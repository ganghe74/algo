#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    lint t, x, y, a, b;
    scanf("%lld", &t);
    while (t--) {
        lint ans = 0;
        scanf("%lld%lld%lld%lld", &x, &y, &a, &b);
        if (b < 2*a) {
            lint m = min(x, y);
            ans += m * b;
            x -= m;
            y -= m;
        }
        ans += x * a;
        ans += y * a;
        printf("%lld\n", ans);
    }
}

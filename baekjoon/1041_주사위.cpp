#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
int main() {
    lint N, a, b, c, d, e, f;
    cin >> N >> a >> b >> c >> d >> e >> f;
    lint min1 = min({a, b, c, d, e, f});
    lint min2 = min({d+e, e+c, c+b, b+d, a+b, a+c, a+d, a+e, f+b, f+c, f+d, f+e});
    lint min3 = min({a+b+c, a+c+e, a+d+e, a+b+d, f+b+c, f+c+e, f+d+e, f+b+d});
    if (N == 1) cout << a + b + c + d + e + f - max({a, b, c, d, e, f});
    else cout << min1 * (5*N*N - 16*N + 12) + min2 * (8*N - 12) + 4 * min3;
}
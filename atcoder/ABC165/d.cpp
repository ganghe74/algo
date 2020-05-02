#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    lint a, b, n;
    cin >> a >> b >> n;

    lint x = min(b-1, n);
    lint ans = (a*x/b) - a*(x/b);
    printf("%lld", ans);
}

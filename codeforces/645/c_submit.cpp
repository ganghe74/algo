#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int t;

int main() {
    cin >> t;
    while (t--) {
        lint x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x2 -= x1;
        y2 -= y1;
        if (x2 < y2)
            swap(x2, y2);
        lint ans = 0;
        ans += y2*(y2+1);
        ans += (x2-y2) * y2;
        ans -= y2;
        cout << ans+1 << '\n';
    }
}

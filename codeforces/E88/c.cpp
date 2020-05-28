#include <bits/stdc++.h>
using namespace std;
using lint = long long;

lint tc, c, h, t;

double f(lint x) {
    double tmp = (x + 1) * h + x * c;
    double tmp2 = 2*x+1;
    return tmp / tmp2;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> tc;
    while (tc--) {
        cin >> h >> c >> t;
        if (h == t) {
            cout << "1\n";
        }
        else if (2*t <= h+c) {
            cout << "2\n";
        }
        else {
            lint l = 0, r = 1e18;
            while (l+1 < r) {
                lint mid = (l+r)/2;
                if (f(mid) >= t) l = mid;
                else r = mid;
            }

            lint ansx = l;
            while (abs(f(ansx+1) - t) < abs(f(ansx)-t)) ansx++;
            while (abs(f(ansx-1) - t) <= abs(f(ansx)-t)) ansx--;
            cout << ansx*2+1 << '\n';
        }
    }
}

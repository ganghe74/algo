#include <bits/stdc++.h>
using namespace std;
using lint = long long;

lint m, q, x, s, xo;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> m;
    while (m--) {
        cin >> q;
        switch (q) {
            case 1:
                cin >> x;
                s += x;
                xo ^= x;
                break;
            case 2:
                cin >> x;
                s -= x;
                xo ^= x;
                break;
            case 3:
                cout << s << '\n';
                break;
            case 4:
                cout << xo << '\n';
                break;
        }
    }
}

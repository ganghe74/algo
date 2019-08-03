#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, a, b, c, d, e, f, g, h;
    cin >> T;
    while (T--) {
        cin >> a >> b >> c >> d >> e >> f >> g >> h;
        cout << max(1, a+e) + 5 * max(1, b+f) + 2 * max(0, c+g) + 2 * (d+h) << endl;
    }
}
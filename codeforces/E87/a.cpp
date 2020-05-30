#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    lint t;
    cin >> t;
    while (t--) {
        lint a, b, c, d;
        cin >> a >> b >> c >> d;
        lint t = b;
        lint sleep = b;
        if (sleep < a && c - d <= 0) cout << "-1\n";
        else {
            if (sleep < a) {
                lint need = a - sleep;
                sleep += (c-d) * (need / (c-d));
                t += c * (need / (c-d));
                if (sleep < a) {
                    sleep += c - d;
                    t += c;
                }
            }
            cout << t << '\n';
        }
    }
}

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        lint a, b;
        cin >> a >> b;
        if (a < b) swap(a, b);
        if (a % b != 0) cout << "-1\n";
        else {
            int cnt = 0;
            while (a > b && !(a%2)) {
                a >>= 1;
                cnt++;
            }
            if (a == b) cout << (cnt+2) / 3 << '\n';
            else cout << "-1\n";
        }
    }
}

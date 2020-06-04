#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int t;
lint n;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        lint ans = 0;
        for (lint i=0; i<64;++i) {
            if (n & (1LL << i)) {
                ans += (1LL << (i+1)) - 1;
            }
        }
        cout << ans << '\n';
    }
}

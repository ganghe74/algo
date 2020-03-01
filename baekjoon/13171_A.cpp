#include <bits/stdc++.h>
using namespace std;
using lint = long long;

const int MOD = 1e9+7;
lint A, X, f[60];

int main() {
    cin >> A >> X;
    f[0] = A % MOD;
    for (int i=1;i<60;++i) f[i] = (f[i-1] * f[i-1]) % MOD;
    lint ans = 1;
    for (int i=59;i>=0;--i) {
        if (X >= 1LL<<i) {
            ans = (ans * f[i]) % MOD;
            X -= 1LL<<i;
        }
    }
    cout << ans;
}

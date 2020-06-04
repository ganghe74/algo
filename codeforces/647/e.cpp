#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint mod = 1e9+7;

lint fastpow(lint a, lint b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    if (b % 2 == 1) return a * fastpow(a, b-1) % mod;
    lint t = fastpow(a, b/2);
    return t*t % mod;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        lint p;
        cin >> n >> p;
        vector<lint> a(n);
        for (int i=0;i<n;++i)
            cin >> a[i];

        if (p == 1) {
            if (n % 2) cout << "1\n";
            else cout << "0\n";
            continue;
        }

        sort(a.rbegin(), a.rend());
        unordered_map<int,int> m;
        int target = -1;
        for (lint x : a) {
            if (target == -1) {
                target = x;
                continue;
            }
            m[x]++;
            while (m[x] == p) {
                m[x] = 0;
                m[++x]++;
            }
            if (m[target] == 1) {
                target = -1;
                m.clear();
            }
        }
        if (target == -1) {
            cout << "0\n";
            continue;
        }
        lint ans = fastpow(p, target);
        for (auto [x, y] : m) {
            if (y) {
                lint d = fastpow(p, x);
                while (y--) {
                    ans = (ans - d + mod) % mod;
                }
            }
        }
        cout << ans << '\n';
    }
}

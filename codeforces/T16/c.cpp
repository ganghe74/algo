#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int ans = 0;
        string s;
        cin >> s;

        unordered_map<lint, unordered_map<lint, bool>> m;
        int r = 10000, c = 10000;
        for (char x : s) {
            lint u = 1LL * r * 20000 + c;
            if (x == 'N') r += 1;
            else if (x == 'S') r -= 1;
            else if (x == 'W') c -= 1;
            else if (x == 'E') c += 1;
            lint v = 1LL * r * 20000 + c;
            if (u > v) swap(u, v);
            if (m[u][v]) ans++;
            else {
                m[u][v] = 1;
                ans += 5;
            }
        }
        cout << ans << '\n';
    }
}

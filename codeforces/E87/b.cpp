#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        int cnt[3] = {0, 0, 0};
        int ans = 1e9;
        int l = 0, r = 0;
        while (r < s.size()) {
            while (r < s.size() && (!cnt[0] || !cnt[1] || !cnt[2])) {
                cnt[s[r]-'1']++;
                r++;
            }
            while (cnt[0] && cnt[1] && cnt[2]) {
                ans = min(ans, r-l);
                cnt[s[l]-'1']--;
                l++;
            }
        }
        if (ans == 1e9) ans = 0;
        cout << ans << '\n';
    }
}

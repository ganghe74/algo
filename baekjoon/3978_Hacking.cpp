#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int t, n, m, k, mod=5000003;
string s, ans;
bool c[5000003];

lint getHash(string s) {
    lint ret = 0;
    for (char x : s) ret = (ret * k + x - 'a' + 1) % mod;
    return ret;
}

bool solve(int depth) {
    if (depth == m) {
        if (!c[getHash(ans)]) return true;
        return false;
    }
    for (int i=0;i<k;++i) {
        ans = ans + char(i + 'a');
        if (solve(depth+1)) return true;
        ans.pop_back();
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        memset(c, 0, sizeof(c));
        cin >> n >> m >> k >> s;
        lint h, first = 1;
        for (int i=0;i<m-1;++i) first = (first * k) % mod;
        for (int i=0;i<=n-m;++i) {
            if (i == 0) h = getHash(s.substr(0,m));
            else h = (k * ((h - (s[i-1] - 'a' + 1) * first) % mod + mod) + s[i+m-1] - 'a' + 1) % mod;
            c[h] = 1;
        }

        ans = "";
        solve(0);
        cout << ans << '\n';
    }
}

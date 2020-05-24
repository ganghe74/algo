#include <bits/stdc++.h>
using namespace std;

int t, n, m;
string a[10];

int diff(const string &s, const string &t) {
    int cnt = 0;
    for (int i=0;i<m;++i)
        if (s[i] != '?' && t[i] != '?' && s[i] != t[i])
            cnt++;
    return cnt;
}

bool check(const string &s) {
    for (int i=0;i<n;++i)
        if (diff(s, a[i]) >= 2)
            return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i=0;i<n;++i)
            cin >> a[i];

        string s = a[0];
        if (check(s)) {
            cout << s << '\n';
            continue;
        }

        bool finds = false;
        for (int anypos=0; anypos<m; ++anypos) {
            s = a[0];
            s[anypos] = '?';
            if (!check(s)) continue;
            char anych = '\0';
            bool ok = true;
            for (int i=0;i<n;++i) {
                if (diff(s, a[i]) == 1) {
                    if (anych == '\0')
                        anych = a[i][anypos];
                    else if (anych != a[i][anypos])
                        ok = false;
                }
            }
            if (ok) {
                if (anych == '\0') anych = 'a';
                s[anypos] = anych;
                finds = true;
                break;
            }
        }
        if (finds) cout << s << '\n';
        else cout << -1 << '\n';
    }
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    int ans = 0;
    string s, t;
    cin >> s;
    reverse(s.begin(), s.end());
    for (char c : s) {
        t = c + t;
        int n = t.size();
        int fail[n] = {0};
        for (int i=1, j=0;i<n;++i) {
            while (j && t[i] != t[j]) j = fail[j-1];
            if (t[i] == t[j]) {
                fail[i] = ++j;
                ans = max(ans, fail[i]);
            }
        }
    }
    cout << ans;
}
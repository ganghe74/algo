#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t, n, k;
    string s;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        cin >> s;

        sort(s.begin(), s.end());
        if (s[0] != s[k-1]) {
            cout << s[k-1] << '\n';
            continue;
        }
        cout << s[0];

        if (s[k] != s[n-1]) {
            for (int i=k;i<n;++i)
                cout << s[i];
        }
        else {
            for (int i=k;i<n;i+=k)
                cout << s[k];
        }
        cout << '\n';

    }
}

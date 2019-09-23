#include <bits/stdc++.h>
using namespace std;
string s, t;
int ans, d[4000][4000];
int main() {
    cin >> s >> t;
    d[0][0] = s[0] == t[0];
    for (int i=1;i<s.size();++i) {
        for (int j=1;j<t.size();++j) {
            if (s[i] == t[j]) d[i][j] = d[i-1][j-1] + 1;
            else d[i][j] = 0;
            ans = max(ans, d[i][j]);
        }
    }
    cout << ans;
}
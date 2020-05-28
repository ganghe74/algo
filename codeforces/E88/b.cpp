#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int t, n, m, x, y;
string a[100];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> m >> x >> y;
        for (int i=0;i<n;++i)
            cin >> a[i];

        lint ans = 0;
        for (int i=0;i<n;++i) {
            for (int j=0;j<m-1;++j) {
                if (a[i][j] == '.') {
                    if (a[i][j+1] == '.') {
                        a[i][j] = a[i][j+1] = '*';
                        if (y < 2*x) {
                            ans += y;
                        }
                        else {
                            ans += 2*x;
                        }
                    }
                    else {
                        a[i][j] = '*';
                        ans += x;
                    }
                }
            }
            if (a[i][m-1] == '.') {
                a[i][m-1] = '.';
                ans += x;
            }
        }
        cout << ans << '\n';
    }
}

#include <bits/stdc++.h>
using namespace std;
const int mod = 1e6+3;

int n, m, k, d[50][1<<15];
string a[15];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> k;
    for (int i=0;i<n;++i)
        cin >> a[i];
    m = a[0].size();

    for (int i=0;i<m;++i) {
        for (char ch='a';ch<='z';++ch) {
            int mask = 0;
            for (int j=0;j<n;++j)
                if (a[j][i] == ch || a[j][i] == '?')
                    mask |= (1 << j);
            if (!i)
                d[i][mask]++;
            else {
                for (int j=0;j<(1<<n);++j)
                    d[i][j&mask] = (d[i][j&mask] + d[i-1][j]) % mod;
            }
        }
    }

    int ans = 0;
    for (int state=0; state<(1<<n); ++state)
        if (__builtin_popcount(state) == k)
            ans = (ans + d[m-1][state]) % mod;

    cout << ans;
}
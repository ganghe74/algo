#include <bits/stdc++.h>
using namespace std;
using lint = long long;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin >> n;
    vector<lint> a(n);
    for (int i=0;i<n;++i) cin >> a[i];
    lint ans = 0;
    for (int i=0;i<n;++i) {
        for (int j=0;j<n;++j) {
            for (int k=0;k<n;++k) {
                ans = max(ans, a[i] | a[j] | a[k]);
            }
        }
    }
    cout << ans;
}

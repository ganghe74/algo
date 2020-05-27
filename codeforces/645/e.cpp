#include <bits/stdc++.h>
using namespace std;
using lint = long long;

lint n, x, a[500010], p[500010], m[500010];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    for (int i=0;i<(n+1)/2;++i)
        cin >> a[i];
    cin >> x;
    for (int i=(n+1)/2;i<n;++i)
        a[i] = x;
    int k = n/2+1;
    for (int i=0;i<k;++i)
        p[0] += a[i];
    for (int i=0;i<n-k;++i)
        p[i+1] = a[i+k]-a[i];

    lint psum = 0;
    for (int i=0;i<n-k;++i) {
        psum += p[i+1];
        m[i+1] = min(m[i], psum);
    }

    while (k <= n) {
        if (p[0] + m[n-k] > 0) {
            cout << k;
            return 0;
        }
        p[0] += a[k];
        k++;
    }

    cout << -1;
}

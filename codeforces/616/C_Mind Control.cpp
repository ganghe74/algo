#include <bits/stdc++.h>
using namespace std;

int t, n, m, k, a[3500];

int main() {
    int t, n, m, k;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &n, &m, &k);
        for (int i=0;i<n;++i) scanf("%d", &a[i]);
        int ans = 0;

        m = m-1;
        k = min(m, k);

        int l = k, r = 0;
        while (l >= 0) {
            int worst = 1e9;
            int ll = m-k;
            int rr = 0;
            while (ll >= 0) {
                worst = min(worst, max(a[l+ll], a[n-1-r-rr]));
                ll--; rr++;
            }
            ans = max(ans, worst);
            l--; r++;
        }

        printf("%d\n", ans);
    }
}

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    lint n, x;
    scanf("%lld%lld", &n, &x);
    vector<lint> d(2*n);
    for (int i=0;i<n;++i) {
        scanf("%lld", &d[i]);
        d[n+i] = d[i];
    }
    lint lmon = 0, rmon = 0;
    lint ans = 0, hugs = 0, day = 0;
    while (rmon < 2*n) {
        day += d[rmon];
        hugs += d[rmon]*(d[rmon]+1)/2;
        
        while (day - d[lmon] >= x) {
            day -= d[lmon];
            hugs -= d[lmon]*(d[lmon]+1)/2;
            lmon++;
        }

        if (day >= x) {
            lint lday = day - x;
            ans = max(ans, hugs - lday*(lday+1)/2);
        }

        rmon++;
    }
    printf("%lld", ans);
}

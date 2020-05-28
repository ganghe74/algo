#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int tc, n, m, price[20], pref[20];
lint c[201];

lint sushi3() {
    int ret = 0;
    c[0] = 0;
    for (int budget = 1; budget <= m; ++budget) {
        int cand = 0;
        for (int dish = 0; dish < n; ++dish)
            if (budget >= price[dish])
                cand = max((lint)cand, c[(budget - price[dish])%201] + pref[dish]);
        c[budget % 201] = cand;
        ret = max(ret, cand);
    }
    return ret;
}

int main() {
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d%d", &n, &m);
        m /= 100;
        for (int i=0;i<n;++i) {
            scanf("%d%d", &price[i], &pref[i]);
            price[i] /= 100;
        }
        printf("%lld\n", sushi3());
    }
}

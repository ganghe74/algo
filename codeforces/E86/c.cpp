#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    int t, a, b, q;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &a, &b, &q);

        vector<bool> period(a*b);
        vector<int> sum(a*b+1);
        int cnt = 0;
        for (int i=0;i<a*b;++i) {
            period[i] = ((i % a % b) != (i % b % a));
            if (period[i]) cnt++;
            sum[i] = cnt;
        }
        sum[a*b] = cnt;

        lint l, r;

        while (q--) {
            scanf("%lld%lld", &l, &r);
            lint ans = 0;

            lint l_num = (l / (a*b) + 1);
            lint r_num = (r / (a*b));
            if (l_num - 1 == r_num) {
                ans += sum[r % (a*b)];
                if (l % (a*b) > 0) ans -= sum[(l-1) % (a*b)];
            }
            else {
                ans += (r_num - l_num) * cnt;

                ans += cnt;
                if (l % (a*b) > 0) ans -= sum[(l-1) % (a*b)];
                ans += sum[r % (a*b)];
            }
            printf("%lld ", ans);


        }
        puts("");
    }
}

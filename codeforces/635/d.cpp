#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int t, r, g, b;

int main() {
    scanf("%d", &t);
    while (t--) {
        lint ans = INT64_MAX;
        vector<lint> a[3];
        scanf("%d%d%d", &r, &g, &b);
        a[0].resize(r);
        a[1].resize(g);
        a[2].resize(b);
        for (int i=0;i<r;++i) scanf("%lld", &a[0][i]);
        for (int i=0;i<g;++i) scanf("%lld", &a[1][i]);
        for (int i=0;i<b;++i) scanf("%lld", &a[2][i]);
        sort(a[0].begin(), a[0].end());
        sort(a[1].begin(), a[1].end());
        sort(a[2].begin(), a[2].end());
        // for (int i=0;i<3;++i) {
        //     for (int x : a[i]) printf("%lld ", x);
        //     puts("");
        // }

        for (auto it_i=a[0].begin();it_i!=a[0].end();++it_i) {
            vector<lint>::iterator lo_g, lo_b;
            lo_g = lower_bound(a[1].begin(), a[1].end(), *it_i);
            for (auto it_j=max(a[1].begin(),lo_g-2);it_j<min(a[1].end(),lo_g+3);++it_j) {
                lint mean = (*it_i + *it_j) / 2;
                lo_b = lower_bound(a[2].begin(), a[2].end(), mean);
                for (auto it_k=max(a[2].begin(),lo_b-2);it_k<min(a[2].end(),lo_b+3);++it_k) {
                    lint x = *it_i;
                    lint y = *it_j;
                    lint z = *it_k;
                    // printf("%lld %lld %lld\n", x, y, z);
                    ans = min(ans, (x-y)*(x-y) + (y-z)*(y-z) + (x-z)*(x-z));
                }
            }

            lo_b = lower_bound(a[2].begin(), a[2].end(), *it_i);
            for (auto it_j=max(a[2].begin(),lo_b-2);it_j<min(a[2].end(),lo_b+3);++it_j) {
                lint mean = (*it_i + *it_j) / 2;
                lo_g = lower_bound(a[1].begin(), a[1].end(), mean);
                for (auto it_k=max(a[1].begin(),lo_g-2);it_k<min(a[1].end(),lo_g+3);++it_k) {
                    lint x = *it_i;
                    lint y = *it_j;
                    lint z = *it_k;
                    // printf("%lld %lld %lld\n", x, y, z);
                    ans = min(ans, (x-y)*(x-y) + (y-z)*(y-z) + (x-z)*(x-z));
                }

            }

        }
        printf("%lld\n", ans);

    }
}
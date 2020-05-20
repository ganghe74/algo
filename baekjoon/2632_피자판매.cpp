#include <bits/stdc++.h>
using namespace std;

int sz, m, n, a[1000], b[1000];
unordered_map<int,int> cnt;

int main() {
    scanf("%d%d%d", &sz, &m, &n);
    for (int i=0;i<m;++i) scanf("%d", &a[i]);
    for (int i=0;i<n;++i) scanf("%d", &b[i]);

    for (int i=0;i<m;++i) {
        int idx = i;
        int s = 0;
        for (int j=1;j<m;++j) {
            s += a[idx];
            idx = (idx + 1) % m;
            cnt[s]++;
        }
    }

    cnt[0]++;
    cnt[accumulate(a, a+m, 0)]++;

    long long ans = 0;
    for (int i=0;i<n;++i) {
        int idx = i;
        int s = 0;
        for (int j=1;j<n;++j) {
            s += b[idx];
            idx = (idx + 1) % n;
            ans += cnt[sz-s];
        }
    }

    ans += cnt[sz];
    ans += cnt[sz-accumulate(b, b+n, 0)];

    printf("%lld\n", ans);
}

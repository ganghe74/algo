#include <bits/stdc++.h>
using namespace std;

int n, x, t[1000000];
map<int,int> m;

void inc(int p) {
    for (t[p+=n]++;p>1;p>>=1) t[p>>1] = t[p] + t[p^1];
}

int query(int l, int r) {
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res += t[l++];
        if (r&1) res += t[--r];
    }
    return res;
}

int main() {
    scanf("%d", &n);
    for (int i=0;i<n;++i) {
        scanf("%d", &x);
        m[x] = i;
    }
    long long ans = 0;
    for (auto pi : m) {
        inc(pi.second);
        ans += query(pi.second+1, n);
    }
    printf("%lld", ans);
}

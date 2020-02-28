#include <bits/stdc++.h>
using namespace std;
using lint = long long;

lint n, m, k, a, b, c;
lint t[2000000];

void build() {
    for (int i=n-1; i>0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, int value) {
    for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

lint query(int l, int r) {
    lint res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res += t[l++];
        if (r&1) res += t[--r];
    }
    return res;
}

int main() {
    scanf("%lld%lld%lld", &n, &m, &k);
    m += k;
    for (int i=0;i<n;++i) scanf("%lld", t + n + i);
    build();
    while (m--) {
        scanf("%lld%lld%lld", &a, &b, &c);
        if (a == 1) modify(b-1, c);
        else printf("%lld\n", query(b-1, c));
    }

}

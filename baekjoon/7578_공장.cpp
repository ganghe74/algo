#include <bits/stdc++.h>
using namespace std;

int n, x, a[1000001], t[1000001];
long long ans;

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
        a[x] = i;
    }
    for (int i=0;i<n;++i) {
        scanf("%d", &x);
        x = a[x];
        inc(x);
        ans += query(x+1, n);
    }
    printf("%lld", ans);
}

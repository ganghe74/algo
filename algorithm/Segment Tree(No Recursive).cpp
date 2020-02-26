// Simple Sum Query.
// TODO: Lazy Propagation
//
#include <bits/stdc++.h>
using namespace std;

int n, t[100000];

void build() {
    for (int i=n-1;i>0;--i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, int value) {
    for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

// Range [l, r)
int query(int l, int r) {
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res += t[l++];
        if (r&1) res += t[--r];
    }
    return res;
}

int main() {
    n = 5;
    for (int i=0;i<5;++i) t[n+i] = i;
    build();

    for (int i=0;i<5;++i) printf("%d ", query(i, i+1));
    puts("");
    printf("%d\n", query(0, 5));
}

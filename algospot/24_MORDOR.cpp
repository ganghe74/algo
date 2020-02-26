#include <bits/stdc++.h>
using namespace std;

int C, N, Q, h, a, b, tmin[200000], tmax[200000];

void build() {
    for (int i=N-1;i>0;--i) {
        tmin[i] = min(tmin[i<<1], tmin[i<<1|1]);
        tmax[i] = max(tmax[i<<1], tmax[i<<1|1]);
    }
}

int minQuery(int l, int r) {
    int res = 1e9;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = min(res, tmin[l++]);
        if (r&1) res = min(res, tmin[--r]);
    }
    return res;
}

int maxQuery(int l, int r) {
    int res = 0;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = max(res, tmax[l++]);
        if (r&1) res = max(res, tmax[--r]);
    }
    return res;
}


int main() {
    scanf("%d", &C);
    while (C--) {
        scanf("%d%d", &N, &Q);
        for (int i=0;i<N;++i) {
            scanf("%d", &h);
            tmin[N+i] = tmax[N+i] = h;
        }
        build();
        while (Q--) {
            scanf("%d%d", &a, &b);
            printf("%d\n", maxQuery(a, b+1) - minQuery(a, b+1));
        }
    }
}

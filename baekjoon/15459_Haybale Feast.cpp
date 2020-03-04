#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int N, F[100000], t[200000];
lint flavor, M;

void build() {
    for (int i=N-1;i>0;--i) t[i] = max(t[i<<1], t[i<<1|1]);
}

int query(int l, int r) {
    int res = 0;
    for (l+=N,r+=N;l<r;l>>=1,r>>=1) {
        if (l&1) res = max(res, t[l++]);
        if (r&1) res = max(res, t[--r]);
    }
    return res;
}

int main() {
    scanf("%d%lld", &N, &M);
    for (int i=0;i<N;++i)
        scanf("%d%d", &F[i], t+N+i);
    build();

    int l = 0, r = 0;
    while (flavor < M) flavor += F[r++];
    int ans = query(l, r);
    while (r < N) {
        flavor += F[r++];
        while (flavor - F[l] >= M) flavor -= F[l++];
        ans = min(ans, query(l, r));
    }
    printf("%d", ans);
}

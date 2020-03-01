#include <bits/stdc++.h>
using namespace std;

int N, p, pos[100001], t[200001];

void init() {
    for (int i=N-1;i>0;--i) t[i] = t[i<<1] + t[i<<1|1];
}

void update(int p, int val) {
    for (t[p+=N]=val;p>1;p>>=1) t[p>>1] = t[p] + t[p^1];
}

int query(int l, int r) {
    int res = 0;
    for (l+=N,r+=N;l<r;l>>=1,r>>=1) {
        if (l&1) res += t[l++];
        if (r&1) res += t[--r];
    }
    return res;
}

int main() {
    scanf("%d", &N);
    for (int i=0;i<N;++i) {
        scanf("%d", &p);
        pos[p] = i;
        t[N+i] = 1;
    }
    init();
    for (int i=1;i<=N;++i) {
        p = pos[(i % 2) ? (i+1)/2 : N-(i-1)/2];
        update(p, 0);
        printf("%d\n", (i%2) ? query(0, p) : query(p, N));
    }
}

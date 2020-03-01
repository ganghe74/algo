#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int N, Q, x, y, a, b;
lint t[200001];

void update(int p, int val) {
    for(t[p+=N]=val;p>1;p>>=1) t[p>>1] = t[p] + t[p^1];
}

lint query(int l, int r) {
    lint res = 0;
    for (l+=N,r+=N;l<r;l>>=1,r>>=1) {
        if (l&1) res += t[l++];
        if (r&1) res += t[--r];
    }
    return res;
}

int main() {
    scanf("%d%d", &N, &Q);
    for (int i=0;i<N;++i) {
        scanf("%d", &x);
        update(i, x);
    }
    while (Q--) {
        scanf("%d%d%d%d", &x, &y, &a, &b);
        if (x > y) swap(x,y);
        printf("%lld\n", query(x-1, y));
        update(a-1, b);
    }
}

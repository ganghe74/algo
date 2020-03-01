#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int N, Q, op, p, q;
lint t[2000001];

void update(int p, int val) {
    for (t[p+=N]+=val;p>1;p>>=1) t[p>>1] = t[p] + t[p^1];
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
    while (Q--) {
        scanf("%d%d%d", &op, &p, &q);
        if (op == 1) update(p-1, q);
        else printf("%lld\n", query(p-1, q));
    }
}

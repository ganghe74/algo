#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int N, M, op, i, j;
lint t[2000001];

void modify(int p, int val) {
    for (t[p+=N]=val;p>1;p>>=1) t[p>>1] = t[p] + t[p^1];
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
    scanf("%d%d", &N, &M);
    while (M--) {
        scanf("%d%d%d", &op, &i, &j);
        if (op) modify(i-1, j);
        else {
            if (i > j) swap(i, j);
            printf("%lld\n", query(i-1,j));
        }
    }
}

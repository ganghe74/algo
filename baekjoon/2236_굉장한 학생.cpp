#include <bits/stdc++.h>
using namespace std;

int N, x, rank2id[500000], id2rank[2][500001], t[1000001];

void update(int p, int val) {
    for (t[p+=N]=val;p>1;p>>=1) t[p>>1] = min(t[p], t[p^1]);
}

int query(int l, int r) {
    int res = 1e9;
    for (l+=N,r+=N;l<r;l>>=1,r>>=1) {
        if (l&1) res = min(res, t[l++]);
        if (r&1) res = min(res, t[--r]);
    }
    return res;
}

int main() {
    fill(t, t+1000001, 1e9);
    scanf("%d", &N);
    for (int i=0;i<N;++i) scanf("%d", &rank2id[i]);
    for (int i=0;i<2;++i) {
        for (int j=0;j<N;++j) {
            scanf("%d", &x);
            id2rank[i][x] = j;
        }
    }

    int ans = 0;
    for (int i=0;i<N;++i) {
        int id = rank2id[i];
        if (query(0, id2rank[0][id]) > id2rank[1][id]) ans++;
        update(id2rank[0][id], id2rank[1][id]);
    }
    printf("%d", ans);
}

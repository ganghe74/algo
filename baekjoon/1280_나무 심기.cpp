#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const int MOD = 1e9+7;

struct Seg {
    int n;
    vector<lint> t;
    Seg(int n) : n(n), t(2*n+1) {}
    void update(int p, int diff) {
        for (t[p+=n]+=diff;p>1;p>>=1) t[p>>1] = t[p] + t[p^1];
    }
    lint query(int l, int r) {
        lint res = 0;
        for (l+=n,r+=n;l<r;l>>=1,r>>=1) {
            if (l&1) res += t[l++];
            if (r&1) res += t[--r];
        }
        return res;
    }
};

int main() {
    int N, p;
    Seg SumSeg(200001), CntSeg(200001);

    scanf("%d%d", &N, &p);
    CntSeg.update(p, 1); SumSeg.update(p, p);

    lint ans = 1;
    for (int i=2;i<=N;++i) {
        scanf("%d", &p);
        lint cost = CntSeg.query(0, p) * p - SumSeg.query(0, p) + SumSeg.query(p, 200000) - CntSeg.query(p, 200000) * p;
        ans = (ans * (cost % MOD)) % MOD;
        CntSeg.update(p, 1); SumSeg.update(p, p);
    }
    printf("%lld", ans);
}

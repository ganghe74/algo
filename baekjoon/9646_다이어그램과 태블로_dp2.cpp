#include <bits/stdc++.h>
using namespace std;

int k, n, row[7], col[7], d[7][1<<7];

int bitcount(int state) {
    return __builtin_popcount(state);
}

vector<int> convert(int state) {
    vector<int> ret;
    for (int i=0;i<7;++i)
        if (state & (1<<i))
            ret.push_back(i);
    return ret;
}

int main() {
    while (scanf("%d", &k) == 1) {
        for (int i=0;i<k;++i) {
            scanf("%d", &row[i]);
            for (int j=0;j<row[i];++j)
                col[j] = i+1;
        }
        scanf("%d", &n);
        memset(d, 0, sizeof(d));
        for (int state=0; state<(1<<n); ++state)
            if (bitcount(state) == col[0])
                d[0][state] = 1;
        for (int i=1;i<row[0];++i) {
            for (int state=0; state<(1<<n); ++state) {
                if (bitcount(state) != col[i]) continue;
                for (int pstate=0; pstate<(1<<n); ++pstate) {
                    if (bitcount(pstate) != col[i-1]) continue;
                    auto v = convert(state);
                    auto pv = convert(pstate);
                    bool ok = true;
                    for (int j=0;j<v.size();++j)
                        if (v[j] < pv[j])
                            ok = false;
                    if (ok)
                        d[i][state] += d[i-1][pstate];
                }
            }
        }
        int ans = 0;
        for (int state=0; state<(1<<n); ++state)
            ans += d[row[0]-1][state];
        printf("%d\n", ans);
    }
}

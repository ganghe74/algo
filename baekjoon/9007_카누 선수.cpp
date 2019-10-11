#include <bits/stdc++.h>
using namespace std;
int main() {
    int T, k, n, d[4][1000];
    scanf("%d", &T);
    while (T--) {
        vector<int> a, b = {int(-1e9), int(1e9), int(1e9+1)};
        scanf("%d%d", &k, &n);
        for (int i=0;i<4;++i)
            for (int j=0;j<n;++j) scanf("%d", &d[i][j]);
        for (int i=0;i<n;++i)
            for (int j=0;j<n;++j) a.push_back(d[0][i] + d[1][j]);
        for (int i=0;i<n;++i)
            for (int j=0;j<n;++j) b.push_back(d[2][i] + d[3][j]);
        sort(b.begin(), b.end());
        b.erase(unique(b.begin(), b.end()), b.end());
        int mgap = 1e9, mval = 1e9;
        for (int x : a) {
            auto it = lower_bound(b.begin(), b.end(), k-x);
            for (int s : {x + *it, x + *(it-1), x + *(it+1)}) {
                if (abs(s-k) < mgap || (abs(s-k) == mgap && s < mval)) {
                    mgap = abs(s-k);
                    mval = s;
                }
            }
        }
        printf("%d\n", mval);
    }
}
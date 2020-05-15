#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int dr[] = {-1, 0};
int dc[] = {0, -1};

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<vector<lint>> a(n, vector<lint>(m));
        for (int i=0;i<n;++i) {
            for (int j=0;j<m;++j) {
                scanf("%lld", &a[i][j]);
                a[i][j] -= i+j;
            }
        }
        lint ans = INT64_MAX;

        for (int i=0;i<n;++i) {
            for (int j=0;j<m;++j) {
                lint target = a[i][j];
                vector<vector<lint>> d(n, vector<lint>(m, INT64_MAX));
                if (a[0][0] < target) continue;
                d[0][0] = a[0][0] - target;
                for (int p=0;p<n;++p) {
                    for (int q=0;q<m;++q) {
                        if (d[p][q] == INT64_MAX) continue;
                        if (p+1 < n && a[p+1][q] >= target) d[p+1][q] = min(d[p+1][q], d[p][q] + abs(a[p+1][q] - target));
                        if (q+1 < m && a[p][q+1] >= target) d[p][q+1] = min(d[p][q+1], d[p][q] + abs(a[p][q+1] - target));
                    }
                }
                ans = min(ans, d[n-1][m-1]);
            }
        }
        printf("%lld\n", ans);
    }
}

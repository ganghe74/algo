#include <bits/stdc++.h>
using namespace std;
int a[100][100];
int f(int r, int c) {
    int ret = 0;
    while (r > 0 && !a[r-1][c]) {
        a[r][c] = 0;
        a[r-1][c] = 1;
        r--;
        ret++;
    }
    return ret;
}
int main() {
    int T, m, n;
    scanf("%d", &T);
    while (T--) {
        int ans = 0;
        scanf("%d%d", &m, &n);
        for (int i=m-1;i>=0;--i) {
            for (int j=0;j<n;++j) scanf("%d", &a[i][j]);
        }
        for (int i=1;i<m;++i) {
            for (int j=0;j<n;++j) {
                if (a[i][j]) ans += f(i, j);
            }
        }
        printf("%d\n", ans);
    }
}
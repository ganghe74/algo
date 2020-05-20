#include <bits/stdc++.h>
using namespace std;

int k, n, a[7][7], ans;
vector<int> row, col;

int getnum(int r, int c) {
    if (r < 0) return 0;
    if (c < 0) return 1;
    return a[r][c];
}

void f(int r, int c) {
    if (r == k) {
        ans++;
        return;
    }
    int lo = max(getnum(r-1, c) + 1, getnum(r, c-1));
    int hi = n - (row[c] - r) + 1;
    int nr = r;
    int nc = c+1;
    if (c+1 >= col[r]) {
        nr++;
        nc = 0;
    }
    for (int i=lo;i<=hi;++i) {
        a[r][c] = i;
        f(nr, nc);
    }
}

int main() {
    while (scanf("%d", &k) == 1) {
        col.resize(k);
        for (int i=0;i<k;++i)
            scanf("%d", &col[i]);
        row.resize(col[0]);
        for (int i=0;i<k;++i)
            for (int j=0;j<col[i];++j)
                row[j] = i+1;
        scanf("%d", &n);
        ans = 0;
        f(0, 0);
        printf("%d\n", ans);
    }
}

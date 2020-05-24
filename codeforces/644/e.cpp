#include <bits/stdc++.h>
using namespace std;

int t, n, a[50][50], d[50][50];

bool check(int r, int c) {
    if (r == n || c == n) return true;
    if (a[r][c] == 0) return false;
    int &ret = d[r][c];
    if (ret != -1) return ret;
    return ret = (check(r+1, c) || check(r, c+1));
}

int main() {
    scanf("%d", &t);
    while (t--) {
        memset(d, -1, sizeof(d));
        scanf("%d", &n);
        for (int i=0;i<n;++i)
            for (int j=0;j<n;++j)
                scanf("%1d", &a[i][j]);
        bool flag = true;
        for (int i=0;i<n;++i) {
            for (int j=0;j<n;++j) {
                if (a[i][j] == 1 && !check(i, j))
                    flag = false;
            }
        }
        puts(flag ? "YES" : "NO");
    }
}

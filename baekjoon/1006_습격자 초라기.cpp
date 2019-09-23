#include <bits/stdc++.h>
using namespace std;
int T, N, W, a[2][10005], d[10005][3];

int solve(int x, int y) {
    if (y == 0 && (!a[0][x] && !a[1][x])) return 0;
    if (y == 1 && (!a[1][x])) return 0;
    if (y == 2 && (!a[0][x])) return 0;
    int &ret = d[x][y];
    if (ret) return ret;
    if (y == 0) {
        ret = solve(x+1, 0) + 2;
        if (a[0][x] + a[0][x+1] <= W && a[1][x] + a[1][x+1] <= W) ret = min(ret, solve(x+2, 0) + 2);
        if (a[0][x] + a[0][x+1] <= W) ret = min(ret, solve(x+1, 1) + 2);
        if (a[1][x] + a[1][x+1] <= W) ret = min(ret, solve(x+1, 2) + 2);
        if (a[0][x] + a[1][x] <= W) ret = min(ret, solve(x+1, 0) + 1);
    }
    else if (y == 1) {
        ret = solve(x+1, 0) + 1;
        if (a[1][x] + a[1][x+1] <= W) ret = min(ret, solve(x+1, 2) + 1);
    }
    else {
        ret = solve(x+1, 0) + 1;
        if (a[0][x] + a[0][x+1] <= W) ret = min(ret, solve(x+1, 1) + 1);
    }
    return ret;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        memset(a, 0, sizeof(a));
        scanf("%d%d", &N, &W);
        for (int i=0;i<2;++i)
            for (int j=0;j<N;++j) scanf("%d", &a[i][j]);
        memset(d, 0, sizeof(d));
        int ans = solve(0, 0);;
        memset(d, 0, sizeof(d));
        a[0][N] = a[0][0];
        ans = min(ans, solve(0, 1));
        memset(d, 0, sizeof(d));
        a[1][N] = a[1][0];
        ans = min(ans, solve(1, 0));
        memset(d, 0, sizeof(d));
        a[0][N] = 0;
        ans = min(ans, solve(0, 2));
        printf("%d\n", ans);
    }
}
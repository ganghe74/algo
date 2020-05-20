#include <bits/stdc++.h>
using namespace std;

int n, k, a[1000][3], d[3000][1000][1<<3];

int solve(int num, int domino, int state) {
    if (num == n*3 && !domino && !state) return 0;
    if (num >= n*3) return -1e9;
    int &ret = d[num][domino][state];
    if (ret != INT32_MIN) return ret;
    if ((state & 1) || !domino) return ret = solve(num+1, domino, state >> 1);
    int r = num / 3, c = num % 3;
    ret = solve(num+1, domino, state >> 1);
    if (c != 2 && !(state & 2))
        ret = max(ret, a[r][c] + a[r][c+1] + solve(num+2, domino-1, state >> 2));
    if (r != n-1)
        ret = max(ret, a[r][c] + a[r+1][c] + solve(num+1, domino-1, (state >> 1) | (1 << 2)));
    return ret;
}

int main() {
    for (int i=0;i<3000;++i)
    for (int j=0;j<1000;++j)
    for (int k=0;k<8;++k)
    d[i][j][k] = INT32_MIN;
    scanf("%d%d", &n, &k);
    for (int i=0;i<n;++i)
        for (int j=0;j<3;++j)
            scanf("%d", &a[i][j]);
    printf("%d", solve(0, k, 0));
}

#include <bits/stdc++.h>
using namespace std;

int R, C, d[188][1<<4];
char a[4][48];

int solve(int num, int state) {
    if (num == R*C)
        return (state) ? INT32_MIN : 0;
    int &ret = d[num][state];
    if (ret != -1) return ret;
    int r = num % R;
    int c = num / R;
    ret = solve(num+1, state >> 1);
    if (a[r][c] == '.' && (state & 1) == 0) {
        if ((r+c) % 2 == 0) {
            if (r+1 < R && c+1 < C && a[r+1][c] == '.' && a[r][c+1] == '.' && !(state & 2))
                ret = max(ret, solve(num+2, (state >> 2) | (1 << (R-2))) + 1);
        }
        else {
            if (r+1 < R && c+1 < C && a[r+1][c] == '.' && a[r+1][c+1] == '.' && !(state & 2))
                ret = max(ret, solve(num+2, (state >> 2) | (1 << (R-1))) + 1);
            if (r-1 >= 0 && c+1 < C && a[r][c+1] == '.' && a[r-1][c+1] == '.' && !(state & (1 << (R-1))))
                ret = max(ret, solve(num+1, (state >> 1) | (3 << (R-2))) + 1);
            if (r+1 < R && c+1 < C && a[r][c+1] == '.' && a[r+1][c+1] == '.')
                ret = max(ret, solve(num+2, (state >> 2) | (3 << (R-2))) + 1);
        }
    }
    return ret;
}

int main() {
    memset(d, -1, sizeof(d));
    scanf("%d%d", &R, &C);
    for (int i=0;i<R;++i)
        scanf(" %s", a[i]);
    printf("%d", solve(0, 0));
}

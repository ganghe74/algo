#include <bits/stdc++.h>
using namespace std;

int n, m, d[250][1<<10];
char a[10][26];

int solve(int num, int state) {
    if (num == n*m)
        return state ? INT32_MIN : 0;
    int &ret = d[num][state];
    if (ret != -1) return ret;
    int r = num % n;
    int c = num / n;
    if (a[r][c] == '1')
        return ret = solve(num+1, state >> 1) + 1;
    if (state & 1)
        return ret = solve(num+1, state >> 1);
    ret = solve(num+1, state >> 1) + 1;
    if (r != n-1 && c != m-1 && (state & 1) == 0 && (state & 2) == 0 && a[r+1][c] == '.' && a[r][c+1] == '.' && a[r+1][c+1] == '.')
        ret = max(ret, solve(num+2, (state >> 2) | (3 << (n-2))) + 16);
    return ret;
}

int main() {
    memset(d, -1, sizeof(d));
    scanf("%d%d", &n, &m);
    for (int i=0;i<n;++i)
        scanf(" %s", a[i]);
    printf("%d", solve(0, 0));
}

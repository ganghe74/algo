#include <bits/stdc++.h>
using namespace std;

int n, d[121][1<<11];
char a[11][11];

int table[4][4] = {
    {100, 70, 40, 0},
    {70, 50, 30, 0},
    {40, 30, 20, 0},
    {0, 0, 0, 0}
};

int price(char a, char b) {
    return table[a-'A'][b-'A'];
}

int solve(int num, int state) {
    if (num == n*n && !state)
        return 0;
    if (num >= n*n)
        return -1e9;
    int &ret = d[num][state];
    if (ret != -1)
        return ret;
    ret = solve(num+1, state >> 1);
    if (!(state & 1)) {
        int r = num / n;
        int c = num % n;
        if (c != n-1 && !(state & 2))
            ret = max(ret, solve(num+2, state >> 2) + price(a[r][c], a[r][c+1]));
        if (r != n-1)
            ret = max(ret, solve(num+1, (state >> 1) | (1 << (n-1))) + price(a[r][c], a[r+1][c]));
    }
    return ret;
}

int main() {
    memset(d, -1, sizeof(d));
    scanf("%d", &n);
    for (int i=0;i<n;++i) {
        for (int j=0;j<n;++j) {
            scanf(" %c", &a[i][j]);
            if (a[i][j] == 'F')
                a[i][j] = 'D';
        }
    }
    printf("%d", solve(0, 0));
}

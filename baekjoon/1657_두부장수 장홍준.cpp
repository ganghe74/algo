#include <bits/stdc++.h>
using namespace std;

int n, m, d[196][1<<14];
char a[14][14];

int table[5][5] = {
    {10, 8, 7, 5, 1},
    {8, 6, 4, 3, 1},
    {7, 4, 3, 2, 1},
    {5, 3, 2, 2, 1},
    {1, 1, 1, 1, 0}
};

int price(char a, char b) {
    return table[a-'A'][b-'A'];
}

int solve(int num, int state) {
    if (num == n*m && !state)
        return 0;
    if (num >= n*m)
        return -1e9;
    int &ret = d[num][state];
    if (ret != -1)
        return ret;
    ret = solve(num+1, state >> 1);
    if (!(state & 1)) {
        int r = num / m;
        int c = num % m;
        if (c != m-1 && !(state & 2))
            ret = max(ret, solve(num+2, state >> 2) + price(a[r][c], a[r][c+1]));
        if (r != n-1)
            ret = max(ret, solve(num+1, (state >> 1) | (1 << (m-1))) + price(a[r][c], a[r+1][c]));
    }
    return ret;
}

int main() {
    memset(d, -1, sizeof(d));
    scanf("%d%d", &n, &m);
    for (int i=0;i<n;++i) {
        for (int j=0;j<m;++j) {
            scanf(" %c", &a[i][j]);
            if (a[i][j] == 'F')
                a[i][j] = 'E';
        }
    }
    printf("%d", solve(0, 0));
}

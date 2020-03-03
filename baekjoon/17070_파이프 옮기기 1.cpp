#include <bits/stdc++.h>
using namespace std;

int dr[] = {0,-1,-1};
int dc[] = {-1,-1,0};
int N, a[16][16], d[16][16][3]; // 0:E, 1:SE, 2:S

int solve(int r, int c, int dir) {
    int pr = r + dr[dir];
    int pc = c + dc[dir];
    if (pr < 0 || pc < 0 || a[r][c]) return 0;
    if (dir == 1 && (a[r-1][c] || a[r][c-1])) return 0;
    int &ret = d[r][c][dir];
    if (ret != -1) return ret;
    if (dir == 0) ret = solve(pr, pc, 0) + solve(pr, pc, 1);
    else if (dir == 1) ret = solve(pr, pc, 0) + solve(pr, pc, 1) + solve(pr, pc, 2);
    else ret = solve(pr, pc, 1) + solve(pr, pc, 2);
    return ret;
}

int main() {
    memset(d, -1, sizeof(d));
    scanf("%d", &N);
    for (int i=0;i<N;++i)
        for (int j=0;j<N;++j) scanf("%d", &a[i][j]);
    d[0][1][0] = 1;
    int ans = 0;
    for (int i=0;i<3;++i) ans += solve(N-1,N-1,i);
    printf("%d", ans);
}

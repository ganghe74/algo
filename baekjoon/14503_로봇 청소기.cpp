#include <bits/stdc++.h>
using namespace std;
bool a[50][50], clean[50][50];
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};
int main() {
    int N, M, r, c, d, x, cnt=0;
    scanf("%d%d", &N, &M);
    scanf("%d%d%d", &r, &c, &d);
    for (int i=0;i<N;++i) {
        for (int j=0;j<M;++j) {
            scanf("%d", &x);
            a[i][j] = clean[i][j] = x;
        }
    }
    while (true) {
        int nr, nc;
        if (!clean[r][c]) {
            clean[r][c] = 1;
            cnt++;
        }
        if (clean[r+1][c] && clean[r-1][c] && clean[r][c+1] && clean[r][c-1]) {
            nr = r-dr[d];
            nc = c-dc[d];
            if (a[nr][nc]) break;
        }
        else {
            d = (d+3) % 4;
            nr = r+dr[d];
            nc = c+dc[d];
            if (clean[nr][nc]) continue;
        }
        r = nr;
        c = nc;
    }
    printf("%d", cnt);
}
#include <bits/stdc++.h>
using namespace std;

int dr[] = {0,-1,0,1};
int dc[] = {1,0,-1,0};
int R, C, T, AC, a[50][50], d[50][50];

void spread() {
    for (int r=0;r<R;++r) {
        for (int c=0;c<C;++c) {
            int amount = a[r][c] / 5;
            for (int k=0;k<4;++k) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (0 <= nr && nr < R && 0 <= nc && nc < C) {
                    if (a[nr][nc] != -1) {
                        d[nr][nc] += amount;
                        d[r][c] -= amount;
                    }
                }
            }
        }
    }
    for (int r=0;r<R;++r) {
        for (int c=0;c<C;++c) {
            a[r][c] += d[r][c];
            d[r][c] = 0;
        }
    }
}

void puri() {
    for (int i=AC-2;i>0;--i) a[i][0] = a[i-1][0];
    for (int i=1;i<C;++i) a[0][i-1] = a[0][i];
    for (int i=1;i<AC;++i) a[i-1][C-1] = a[i][C-1];
    for (int i=C-1;i>1;--i) a[AC-1][i] = a[AC-1][i-1];
    for (int i=AC+2;i<R;++i) a[i-1][0] = a[i][0];
    for (int i=1;i<C;++i) a[R-1][i-1] = a[R-1][i];
    for (int i=R-1;i>AC;--i) a[i][C-1] = a[i-1][C-1];
    for (int i=C-1;i>1;--i) a[AC][i] = a[AC][i-1];
    a[AC-1][1] = a[AC][1] = 0;
}

int main() {
    scanf("%d%d%d", &R, &C, &T);
    for (int i=0;i<R;++i) {
        for (int j=0;j<C;++j) {
            scanf("%d", &a[i][j]);
            if (a[i][j] == -1) AC = i;
        }
    }
    while (T--) {
        spread();
        puri();
    }
    int cnt = 0;
    for (int i=0;i<R;++i)
        for (int j=0;j<C;++j)
            cnt += max(a[i][j], 0);
    printf("%d", cnt);
}

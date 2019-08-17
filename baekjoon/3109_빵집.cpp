#include <bits/stdc++.h>
using namespace std;
int R, C, cnt;
char x;
bool a[10000][500];

bool dfs(int r, int c) {
    a[r][c] = 1;
    if (c == C-1) return true;
    for (int dr : {-1,0,1}) {
        int nr = r + dr;
        int nc = c + 1;
        if (0 <= nr && nr < R) {
            if (!a[nr][nc]) {
                if (dfs(nr,nc)) return true;
            }
        }
    }
    return false;
}

int main() {
    scanf("%d%d", &R, &C);
    for (int i=0;i<R;++i) {
        for (int j=0;j<C;++j) {
            scanf(" %c", &x);
            if (x == 'x') a[i][j] = 1;
        }

    }
    for (int i=0;i<R;++i) {
        if (!a[i][0]) {
            if (dfs(i,0)) cnt++;
        }
    }

    printf("%d", cnt);
}
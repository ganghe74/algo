#include <bits/stdc++.h>
using namespace std;

int R, C;
char a[20][20];
int dr[] = {0,0,1,-1};
int dc[] = {1,-1,0,0};
bool used[26];

int dfs(int r, int c) {
    used[a[r][c]-'A'] = 1;
    int ret = 0;
    for (int k=0;k<4;++k) {
        int nr = r + dr[k];
        int nc = c + dc[k];
        if (0 <= nr && nr < R && 0 <= nc && nc < C) {
            if (!used[a[nr][nc]-'A']) ret = max(ret, dfs(nr,nc));
        }
    }
    used[a[r][c]-'A'] = 0;
    return ret + 1;
}

int main() {
    scanf("%d%d", &R, &C);
    for (int i=0;i<R;++i) {
        for (int j=0;j<C;++j) scanf(" %c", &a[i][j]);
    }
    printf("%d", dfs(0,0));
}
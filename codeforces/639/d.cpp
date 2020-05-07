#include <bits/stdc++.h>
using namespace std;

const int dr[] = {1,-1,0,0};
const int dc[] = {0,0,1,-1};
int n, m;
char a[1000][1000];
bool visited[1000][1000];

void dfs(int r, int c) {
    visited[r][c] = 1;
    for (int k=0;k<4;++k) {
        int nr = r + dr[k];
        int nc = c + dc[k];
        if (0 <= nr && nr < n && 0 <= nc && nc < m)
            if (a[nr][nc] == '#' && !visited[nr][nc])
                dfs(nr, nc);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            scanf(" %c", &a[i][j]);

    int zerorow = 0, zerocol = 0;
    for (int i=0;i<n;++i) {
        int seg = 0;
        char bc = '.';
        for (int j=0;j<m;++j) {
            if (a[i][j] == '#' && bc == '.') seg++;
            bc = a[i][j];
        }
        if (seg == 0) zerorow++;
        if (seg >= 2) {
            puts("-1");
            return 0;
        }
    }
    for (int j=0;j<m;++j) {
        int seg = 0;
        char bc = '.';
        for (int i=0;i<n;++i) {
            if (a[i][j] == '#' && bc == '.') seg++;
            bc = a[i][j];
        }
        if (seg == 0) zerocol++;
        if (seg >= 2) {
            puts("-1");
            return 0;
        }
    }
    
    if ((zerorow && !zerocol) || (!zerorow && zerocol)) {
        puts("-1");
        return 0;
    }

    int cnt = 0;
    for (int i=0;i<n;++i) {
        for (int j=0;j<m;++j) {
            if (a[i][j] == '#' && !visited[i][j]) {
                dfs(i, j);
                cnt++;
            }
        }
    }
    printf("%d", cnt);
}

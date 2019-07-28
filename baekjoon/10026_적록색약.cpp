#include <bits/stdc++.h>
using namespace std;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int N, cnt1, cnt2;
char a[100][100];
bool visited[100][100];

void dfs(int r, int c, bool rg) {
    visited[r][c] = 1;
    for (int k=0;k<4;++k) {
        int nr = r + dx[k];
        int nc = c + dy[k];
        if (0 <= nr && nr < N && 0 <= nc && nc < N) {
            if (!visited[nr][nc]) {
                if (a[nr][nc] == a[r][c] || (rg && a[r][c] != 'B' && a[nr][nc] != 'B')) {
                    dfs(nr, nc, rg);
                }
            }
        }
    }
}

int main() {
    scanf("%d", &N);
    for (int i=0;i<N;++i) {
        for (int j=0;j<N;++j) {
            scanf(" %c", &a[i][j]);
        }
    }
    for (int i=0;i<N;++i) {
        for (int j=0;j<N;++j) {
            if (!visited[i][j]) {
                dfs(i, j, 0);
                cnt1++;
            }
        }
    }
    memset(visited, 0, sizeof(visited));
    for (int i=0;i<N;++i) {
        for (int j=0;j<N;++j) {
            if (!visited[i][j]) {
                dfs(i, j, 1);
                cnt2++;
            }
        }
    }
    printf("%d %d", cnt1, cnt2);
}
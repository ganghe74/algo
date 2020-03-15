#include <bits/stdc++.h>
using namespace std;

int dr[] = {0,0,1,-1};
int dc[] = {1,-1,0,0};
int N, M, d[50][50][1<<6];
char a[50][50];
queue<tuple<int,int,int>> q;

int main() {
    scanf("%d%d", &N, &M);
    for (int i=0;i<N;++i) {
        for (int j=0;j<M;++j) {
            scanf(" %c", &a[i][j]);
            if (a[i][j] == '0') {
                q.push({i, j, 0});
                d[i][j][0] = 1;
            }
        }
    }
    
    int ans = 1e9;
    while (!q.empty()) {
        auto [r, c, status] = q.front(); q.pop();
        for (int k=0;k<4;++k) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            int nstatus = status;
            if (0 <= nr && nr < N && 0 <= nc && nc < M) {
                if (a[nr][nc] == '#') continue;
                if (isupper(a[nr][nc]) && !(status & (1 << (a[nr][nc] - 'A')))) continue;
                if (islower(a[nr][nc])) nstatus |= 1 << (a[nr][nc] - 'a');
                if (d[nr][nc][nstatus]) continue;
                q.push({nr, nc, nstatus});
                d[nr][nc][nstatus] = d[r][c][status] + 1;
                if (a[nr][nc] == '1') ans = min(ans, d[nr][nc][nstatus]);
            }
        }
    }

    printf("%d", (ans == 1e9) ? -1 : ans-1);
}

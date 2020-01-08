#include <bits/stdc++.h>
using namespace std;
int N, M, T, gramr, gramc, a[100][100];
int d[100][100];
int dr[] = {0,0,1,-1};
int dc[] = {1,-1,0,0};
int main() {
    scanf("%d%d%d", &N, &M, &T);
    for (int i=0;i<N;++i) {
        for (int j=0;j<M;++j) {
            scanf("%d", &a[i][j]);
            if (a[i][j] == 2) {
                gramr = i;
                gramc = j;
            }
        }
    }
    queue<pair<int,int>> q;
    q.push({0,0});
    d[0][0] = 1;
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for (int k=0;k<4;++k) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (0 <= nr && nr < N && 0 <= nc && nc < M) {
                if (a[nr][nc] != 1 && !d[nr][nc]) {
                    q.push({nr, nc});
                    d[nr][nc] = d[r][c] + 1;
                }
            }
        }
    }
    int ans = d[N-1][M-1];
    if (!ans) ans = 1e9;
    if (d[gramr][gramc]) ans = min(ans, d[gramr][gramc] + N - gramr - 1 + M - gramc - 1);
    if (ans > T + 1) puts("Fail");
    else printf("%d", ans-1);
}
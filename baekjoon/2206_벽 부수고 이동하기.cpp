#include <bits/stdc++.h>
using namespace std;

bool a[1001][1001];
int d[1001][1001];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i=0;i<N;++i) {
        for (int j=0;j<M;++j) scanf("%1d", &a[i][j]);
    }
    queue<pair<int,int>> q, q2;
    q.push({0,0});
    d[0][0] = 1;
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for (int k=0;k<4;++k) {
            int nr = r + dx[k];
            int nc = c + dy[k];
            if (0 <= nr && nr < N && 0 <= nc && nc < M) {
                if (!d[nr][nc]) {
                    if (a[nr][nc] == 0) q.push({nr,nc});
                    else q2.push({nr,nc});
                    d[nr][nc] = d[r][c] + 1;
                }
            }
        }
    }
    while (!q2.empty()) {
        int r = q2.front().first;
        int c = q2.front().second;
        q2.pop();
        for (int k=0;k<4;++k) {
            int nr = r + dx[k];
            int nc = c + dy[k];
            if (0 <= nr && nr < N && 0 <= nc && nc < M) {
                if (a[nr][nc] == 0) {
                    if (!d[nr][nc] || d[r][c] + 1 < d[nr][nc]) {
                        q2.push({nr,nc});
                        d[nr][nc] = d[r][c] + 1;
                    }
                }
            }
        }
    }
    if (d[N-1][M-1]) printf("%d", d[N-1][M-1]);
    else puts("-1");
}
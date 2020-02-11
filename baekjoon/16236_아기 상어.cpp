#include <bits/stdc++.h>
using namespace std;

int dr[] = {0,0,1,-1};
int dc[] = {1,-1,0,0};
int N, lvl = 2, ex, t, a[20][20], d[21][21];
pair<int,int> shark, mob;

int main() {
    scanf("%d", &N);
    for (int i=0;i<N;++i) {
        for (int j=0;j<N;++j) {
            scanf("%d", &a[i][j]);
            if (a[i][j] == 9) {
                a[i][j] = 0;
                shark.first = i;
                shark.second = j;
            }
        }
    }

    while (true) {
        mob = {20,20};
        memset(d, 0, sizeof(d));
        d[20][20] = 1e9;
        queue<pair<int,int>> q;
        q.push({shark.first, shark.second});
        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            for (int k=0;k<4;++k) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (0 <= nr && nr < N && 0 <= nc && nc < N) {
                    if (!d[nr][nc] && a[nr][nc] <= lvl) {
                        q.push({nr, nc});
                        d[nr][nc] = d[r][c] + 1;
                        if (0 < a[nr][nc] && a[nr][nc] < lvl) {
                            int d1 = d[mob.first][mob.second];
                            int d2 = d[nr][nc];
                            if (d2 < d1 || (d1 == d2 && (nr < mob.first || (nr == mob.first && nc < mob.second))))
                                mob = {nr, nc};
                        }
                    }
                }
            }
        }
        if (a[mob.first][mob.second] >= lvl || mob.first == 20) break;
        a[mob.first][mob.second] = 0;
        t += d[mob.first][mob.second];
        shark = mob;
        if (++ex == lvl) {
            ex = 0;
            lvl++;
        }
    }
    printf("%d", t);
}

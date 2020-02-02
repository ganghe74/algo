#include <bits/stdc++.h>
using namespace std;

int dr[] = {1,-1,0,0};
int dc[] = {0,0,1,-1};
bool c[50][50];
int a[50][50], dist[50][50], N, M, ans = 1e9;
vector<pair<int,int>> shops, chosen;

void choice(int depth) {
    if (depth == shops.size() || chosen.size() == M) {
        if (chosen.empty()) return;
        int distsum = 0;
        memset(dist, 0, sizeof(dist));
        queue<pair<int,int>> q;
        for (auto pi : chosen) {
            q.push(pi);
            dist[pi.first][pi.second] = 1;
        }
        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            for (int k=0;k<4;++k) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (0 <= nr && nr < N && 0 <= nc && nc < N) {
                    if (!dist[nr][nc]) {
                        q.push({nr, nc});
                        dist[nr][nc] = dist[r][c] + 1;
                        if (a[nr][nc] == 1) distsum += dist[nr][nc] - 1;
                    }
                }
            }
        }
        ans = min(ans, distsum);
        return;
    }
    chosen.push_back(shops[depth]);
    choice(depth+1);
    chosen.pop_back();
    choice(depth+1);
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i=0;i<N;++i) {
        for (int j=0;j<N;++j) {
            scanf("%d", &a[i][j]);
            if (a[i][j] == 2) shops.push_back({i, j});
        }
    }
    choice(0);
    printf("%d", ans);
}

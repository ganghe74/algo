#include <bits/stdc++.h>
using namespace std;
using lint = long long;

const int dr[] = {1,-1,0,0};
const int dc[] = {0,0,1,-1};
int n, m, t, a[1000][1000], d[1000][1000];

int main() {
    scanf("%d%d%d", &n, &m, &t);
    for (int i=0;i<n;++i) {
        for (int j=0;j<m;++j) {
            scanf(" %1d", &a[i][j]);
        }
    }

    memset(d, -1, sizeof(d));
    queue<pair<int,int>> q;

    for (int i=0;i<n;++i) {
        for (int j=0;j<m;++j) {
            bool good = false;
            for (int k=0;k<4;++k) {
                int nr = i + dr[k];
                int nc = j + dc[k];
                if (0 <= nr && nr < n && 0 <= nc && nc < m)
                    if (a[nr][nc] == a[i][j])
                        good = true;
            }
            if (good) {
                d[i][j] = 0;
                q.push({i, j});
            }

        }
    }

    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        for (int k=0;k<4;++k) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (0 <= nr && nr < n && 0 <= nc && nc < m) {
                if (d[nr][nc] == -1) {
                    q.push({nr, nc});
                    d[nr][nc] = d[r][c] + 1;
                }
            }
        }
    }

    while (t--) {
        int i, j;
        lint p;
        scanf("%d%d%lld", &i, &j, &p);
        i--; j--;
        if (d[i][j] == -1) printf("%d\n", a[i][j]);
        else if (p <= d[i][j]) printf("%d\n", a[i][j]);
        else printf("%d\n", ((p-d[i][j])%2) ? (1-a[i][j]) : a[i][j]);
    }
}

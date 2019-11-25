#include <bits/stdc++.h>
using namespace std;

int dr[] = {-2,-2,-1,-1,1,1,2,2};
int dc[] = {-1,1,-2,2,-2,2,-1,1};

int d[300][300];
bool visited[300][300];

int main() {
    int T, L, r, c;
    scanf("%d", &T);
    while (T--) {
        memset(d, 0, sizeof(d));
        memset(visited, 0, sizeof(visited));
        scanf("%d%d%d", &L, &r, &c);
        queue<pair<int,int>> q;
        visited[r][c] = 1;
        q.push({r,c});
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int k=0;k<8;++k) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (0 <= nr && nr < L && 0 <= nc && nc < L) {
                    if (!visited[nr][nc]) {
                        d[nr][nc] = d[r][c] + 1;
                        visited[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
        }
        scanf("%d%d", &r, &c);
        printf("%d\n", d[r][c]);
    }
}
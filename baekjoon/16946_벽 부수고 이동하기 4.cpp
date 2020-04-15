#include <bits/stdc++.h>
using namespace std;

int dr[] = {0,0,1,-1};
int dc[] = {1,-1,0,0};
int N, M, group, a[1000][1000], g[1000][1000], w[100000];
bool visited[1000][1000];

int main() {
    scanf("%d%d", &N, &M);
    for (int i=0;i<N;++i)
        for (int j=0;j<M;++j) scanf("%1d", &a[i][j]);

    for (int i=0;i<N;++i) {
        for (int j=0;j<M;++j) {
            if (!a[i][j] && !visited[i][j]) {
                queue<pair<int,int>> q;
                q.push({i, j});

                int area = 0;
                visited[i][j] = 1;
                ++group;

                while (!q.empty()) {
                    auto [r, c] = q.front(); q.pop();
                    g[r][c] = group;
                    area++;
                    for (int k=0;k<4;++k) {
                        int nr = r + dr[k];
                        int nc = c + dc[k];
                        if (0 <= nr && nr < N && 0 <= nc && nc < M) {
                            if (!a[nr][nc] && !visited[nr][nc]) {
                                visited[nr][nc] = 1;
                                q.push({nr, nc});
                            }
                        }
                    }
                }

                w[group] = area;
            }
        }
    }

    for (int i=0;i<N;++i) {
        for (int j=0;j<M;++j) {
            if (a[i][j]) {
                set<int> s;
                for (int k=0;k<4;++k) {
                    int nr = i + dr[k];
                    int nc = j + dc[k];
                    if (0 <= nr && nr < N && 0 <= nc && nc < M)
                        if (!a[nr][nc])
                            s.insert(g[nr][nc]);
                }
                int sum = 1;
                for (int x : s) sum += w[x];
                printf("%d", sum % 10);
            }
            else printf("0");
        }
        puts("");
    }
}

#include <bits/stdc++.h>
using namespace std;
int N;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int a[100][100];
bool visited[100][100];

void bfs(int r, int c, int h) {
    queue<pair<int,int>> q;
    q.push({r, c});
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for (int k=0;k<4;++k) {
            int nr = r + dx[k];
            int nc = c + dy[k];
            if (0 <= nr && nr < N && 0 <= nc && nc < N) {
                if (a[nr][nc] > h && !visited[nr][nc]) {
                    visited[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }
}

int main() {
    scanf("%d", &N);
    for (int i=0;i<N;++i) {
        for (int j=0;j<N;++j) scanf("%d", &a[i][j]);
    }
    int ans = 0;
    for (int h=0;h<=100;++h) {
        memset(visited, 0, sizeof(visited));
        int cnt = 0;
        for (int i=0;i<N;++i) {
            for (int j=0;j<N;++j) {
                if (!visited[i][j] && a[i][j] > h) {
                    bfs(i, j, h);
                    cnt++;
                }
            }
        }
        ans = max(ans, cnt);
    }
    printf("%d", ans);
}
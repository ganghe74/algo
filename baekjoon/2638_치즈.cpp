#include <bits/stdc++.h>
using namespace std;

int dr[] = {0,0,1,-1};
int dc[] = {1,-1,0,0};
int N, M, ans, cnt, a[100][100], air[100][100];
bool visited[100][100];
queue<pair<int,int>> q;

void dfs(int r, int c) {
    if (a[r][c]) {
        if (++air[r][c] == 2) q.push({r, c});
        return;
    }
    visited[r][c] = 1;
    for (int k=0;k<4;++k) {
        int nr = r + dr[k];
        int nc = c + dc[k];
        if (0 <= nr && nr < N && 0 <= nc && nc < M) {
            if (!visited[nr][nc]) dfs(nr, nc);
        }
    }
}

void step() {
    memset(visited, 0, sizeof(visited));
    memset(air, 0, sizeof(air));
    dfs(0,0);
    cnt -= q.size();
    ans++;
    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        a[r][c] = 0;
    }
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i=0;i<N;++i) {
        for (int j=0;j<M;++j) {
            scanf("%d", &a[i][j]);
            cnt += a[i][j];
        }
    }
    while (cnt) step();
    printf("%d", ans);
}

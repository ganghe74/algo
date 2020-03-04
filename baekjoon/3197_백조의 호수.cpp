#include <bits/stdc++.h>
using namespace std;

int dr[] = {0,0,1,-1};
int dc[] = {1,-1,0,0};
int R, C, group, cnt, a[1500][1500];
bool ice[1500][1500], visited[1500][1500];
pair<int,int> swan[2];

vector<int> p;

queue<tuple<int,int,int>> q, q_next;

int Find(int u) {
    if (u == p[u]) return u;
    return p[u] = Find(p[u]);
}

void Union(int u, int v) {
    u = Find(u); v = Find(v);
    p[u] = v;
}

void dfs(int r, int c) {
    visited[r][c] = 1;
    if (ice[r][c]) {
        q_next.push({r, c, group});
        return;
    }
    a[r][c] = group;
    for (int k=0;k<4;++k) {
        int nr = r + dr[k];
        int nc = c + dc[k];
        if (0 <= nr && nr < R && 0 <= nc && nc < C) {
            if (!visited[nr][nc]) dfs(nr, nc);
        }
    }
}

void step() {
    swap(q, q_next);
    while (!q.empty()) {
        auto [r, c, group] = q.front(); q.pop();
        a[r][c] = group;
        for (int k=0;k<4;++k) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (0 <= nr && nr < R && 0 <= nc && nc < C) {
                if (a[nr][nc]) Union(a[r][c], a[nr][nc]);
                if (!visited[nr][nc]) {
                    visited[nr][nc] = 1;
                    q_next.push({nr, nc, a[r][c]});
                }
            }
        }
    }
}

int main() {
    scanf("%d%d", &R, &C);
    for (int i=0;i<R;++i) {
        for (int j=0;j<C;++j) {
            char x;
            scanf(" %c", &x);
            if (x == 'L') swan[cnt++] = {i, j};
            if (x == 'X') ice[i][j] = 1;
        }
    }

    for (int i=0;i<R;++i) {
        for (int j=0;j<C;++j) {
            if (!visited[i][j] && !ice[i][j]) {
                group++;
                dfs(i, j);
            }
        }
    }
    p.resize(group+1);
    iota(p.begin(), p.end(), 0);

    int ans = 0;
    while (Find(a[swan[0].first][swan[0].second]) != Find(a[swan[1].first][swan[1].second])) ans++, step();

    printf("%d", ans);
}

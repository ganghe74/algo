#include <bits/stdc++.h>
using namespace std;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int N, K, x, y, ans, p[100001], w[100001], a[2000][2000];
bool c[2000][2000];

queue<pair<int,int>> q, q_next;

int Find(int u) {
    if (u == p[u]) return u;
    return p[u] = Find(p[u]);
}

void Union(int u, int v) {
    u = Find(u); v = Find(v);
    if (u == v) return;
    w[v] += w[u];
    p[u] = p[v];
}

void step() {
    swap(q, q_next);
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int k=0;k<4;++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (0 <= nx && nx < N && 0 <= ny && ny < N) {
                if (a[nx][ny]) Union(a[x][y], a[nx][ny]);
                if (!c[nx][ny]) {
                    q_next.push({nx, ny});
                    a[nx][ny] = a[x][y];
                    c[nx][ny] = 1;
                }
            }
        }
    }
    q = q_next;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int k=0;k<4;++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (0 <= nx && nx < N && 0 <= ny && ny < N)
                if (a[nx][ny]) Union(a[x][y], a[nx][ny]);
        }
    }
}

int main() {
    scanf("%d%d", &N, &K);
    for (int i=1;i<=K;++i) {
        scanf("%d%d", &x, &y);
        x--; y--;
        a[x][y] = p[i] = i;
        c[x][y] = w[i] = 1;
        q_next.push({x, y});
        for (int k=0;k<4;++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (0 <= nx && nx < N && 0 <= ny && ny < N)
                if (a[nx][ny]) Union(a[x][y], a[nx][ny]);
        }
    }
    while (w[Find(1)] < K) step(), ans++;
    printf("%d", ans);
}

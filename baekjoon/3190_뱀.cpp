#include <bits/stdc++.h>
using namespace std;

int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

int N, K, L, r, c, X, a[101][101];
char C;
queue<pair<int,int>> snake;
queue<pair<int,char>> q;

int main() {
    scanf("%d%d", &N, &K);
    while (K--) {
        scanf("%d%d", &r, &c);
        a[r][c] = 2;
    }
    scanf("%d", &L);
    while (L--) {
        scanf("%d %c", &X, &C);
        q.push({X, C});
    }
    int T=0, DIR=0;
    r=1; c=1; a[1][1] = 1; snake.push({1, 1});
    while (true) {
        int nr = r + dr[DIR];
        int nc = c + dc[DIR];
        T++;
        if (!(0 < nr && nr <= N && 0 < nc && nc <= N)) break;
        if (a[nr][nc] == 1) break;
        if (a[nr][nc] != 2) {
            tie(r, c) = snake.front(); snake.pop();
            a[r][c] = 0;
        }
        a[nr][nc] = 1;
        snake.push({nr, nc});
        r=nr; c=nc;
        if (!q.empty()) {
            tie(X, C) = q.front();
            if (T == X) {
                if (C == 'D') DIR = (DIR + 1) % 4;
                else DIR = (DIR + 3) % 4;
                q.pop();
            }
        }
    }
    printf("%d", T);
}
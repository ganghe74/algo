#include <bits/stdc++.h>
using namespace std;
bool visited[100][100];
int M, N, cnt;
int dr[] = {0,1,0,-1};
int dc[] = {1,0,-1,0};

void go(int r, int c, int d) {
    visited[r][c] = 1;
    int nr = r + dr[d];
    int nc = c + dc[d];
    if (!(0 <= nr && nr < M && 0 <= nc && nc < N) || visited[nr][nc]) {
        d = (d + 1) % 4;
        nr = r + dr[d];
        nc = c + dc[d];
        cnt++;
        if (visited[nr][nc]) return;
    }
    go(nr, nc, d);
}

int main() {
    scanf("%d%d", &M, &N);
    go(0,0,0);
    printf("%d", cnt-1);
}
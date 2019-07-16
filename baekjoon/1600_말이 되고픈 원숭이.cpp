#include <bits/stdc++.h>
using namespace std;
int a[200][200];
int d[200][200][31];
int dx[12] = {0,0,1,-1,-2,-2,-1,-1,1,1,2,2};
int dy[12] = {1,-1,0,0,-1,1,-2,2,-2,2,-1,1};
int main() {
    int K, W, H;
    scanf("%d%d%d", &K, &W, &H);
    for (int i=0;i<H;++i) {
        for (int j=0;j<W;++j) scanf("%d", &a[i][j]);
    }
    queue<tuple<int,int,int>> q;
    q.push({0,0,0});
    d[0][0][0] = 1;
    while (!q.empty()) {
        int r, c, jump;
        tie(r, c, jump) = q.front();
        q.pop();
        int x = (jump > K) ? 4 : 12;
        for (int i=0;i<x;++i) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            int njump = jump + (i >= 4);
            if (njump <= K) {
                if (0 <= nr && nr < H && 0 <= nc && nc < W) {
                    if (a[nr][nc] == 0 && d[nr][nc][njump] == 0) {
                        d[nr][nc][njump] = d[r][c][jump] + 1;
                        q.push({nr, nc, njump});
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i=0;i<=K;++i) {
        if (ans == 0) ans = d[H-1][W-1][i];
        if (d[H-1][W-1][i] != 0) ans = min(ans, d[H-1][W-1][i]);
    }
    printf("%d", ans-1);
}
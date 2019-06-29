#include <bits/stdc++.h>
using namespace std;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool a[10][10];
int d[10][10];
void cover(int r, int c) {
    for (int i=0;i<10;++i) {
        a[r][i] = 1;
        a[i][c] = 1;
    }
}
int main() {
    int r, c;
    char x;
    scanf("%d%d", &r, &c);
    for (int i=0;i<10;++i) {
        for (int j=0;j<10;++j) {
            scanf(" %c", &x);
            if (x == 'o') cover(i,j);
        }
    }
    queue<pair<int,int>> q;
    q.push({r-1,c-1});
    d[r-1][c-1] = 1;
    while (!q.empty()) {
        tie(r, c) = q.front();
        q.pop();
        for (int k=0;k<4;++k) {
            int nr = r + dx[k];
            int nc = c + dy[k];
            if (0 <= nr && nr < 10 && 0 <= nc && nc < 10) {
                if (!d[nr][nc]) {
                    q.push({nr,nc});
                    d[nr][nc] = d[r][c] + 1;
                }
            }
        }
    }
    int ans = 1000;
    for (int i=0;i<10;++i) {
        for (int j=0;j<10;++j) {
            if (!a[i][j]) ans = min(ans, d[i][j]);
        }
    }
    printf("%d", ans-1);
}
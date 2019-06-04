#include <bits/stdc++.h>
using namespace std;
int M, N;
int a[500][500];
int d[500][500];
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
int go(int r, int c) {
    if (r == M-1 && c == N-1) return 1;
    if (d[r][c] != -1) return d[r][c];
    d[r][c] = 0;
    for (int k=0;k<4;++k) {
        int nr = r + dx[k];
        int nc = c + dy[k];
        if (0 <= nr && nr < M && 0 <= nc && nc < N)
            if (a[nr][nc] < a[r][c])
                d[r][c] += go(nr,nc);
    }
    return d[r][c];
}
int main() {
    scanf("%d%d", &M, &N);
    for (int i=0;i<M;++i) {
        for (int j=0;j<N;++j) scanf("%d", &a[i][j]);
    }
    memset(d, -1, sizeof(d));
    printf("%d", go(0,0));
}
#include <bits/stdc++.h>
using namespace std;

int N, M, ans;
int a[8][8], b[8][8];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void dfs(int r, int c) {
    b[r][c] = 2;
    for (int k=0;k<4;++k) {
        int nr = r + dx[k];
        int nc = c + dy[k];
        if (0 <= nr && nr < N && 0 <= nc && nc < M) {
            if (!b[nr][nc]) dfs(nr, nc);
        }
    }
}

int count() {
    for (int i=0;i<N;++i)
        for (int j=0;j<M;++j) b[i][j] = a[i][j];
    for (int i=0;i<N;++i) {
        for (int j=0;j<M;++j) {
            if (b[i][j] == 2) dfs(i, j);
        }
    }
    int cnt = 0;
    for (int i=0;i<N;++i) {
        for (int j=0;j<M;++j) {
            if (!b[i][j]) cnt++;
        }
    }
    return cnt;
}

void choice(int pos, int cnt) {
    if (cnt == 0) {
        ans = max(ans, count());
        return;
    }
    for (int i=pos;pos<N*M;++pos) {
        int r = pos / M;
        int c = pos % M;
        if (!a[r][c]) {
            a[r][c] = 1;
            choice(i+1, cnt-1);
            a[r][c] = 0;
        }
    }
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i=0;i<N;++i) {
        for (int j=0;j<M;++j) scanf("%d", &a[i][j]);
    }
    choice(0, 3);
    printf("%d", ans);
}
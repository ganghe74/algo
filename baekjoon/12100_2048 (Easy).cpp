#include <bits/stdc++.h>
using namespace std;

int dr[] = {0,0,1,-1};
int dc[] = {1,-1,0,0};
int N, ans;
bool merged[20][20];
vector<vector<int>> a;

void push_block(int r, int c, int k) {
    if (!a[r][c]) return;
    int nr = r + dr[k];
    int nc = c + dc[k];
    if (0 <= nr && nr < N && 0 <= nc && nc < N) {
        if (!a[nr][nc]) {
            a[nr][nc] = a[r][c];
            a[r][c] = 0;
            merged[nr][nc] = merged[r][c];
            merged[r][c] = 0;
            push_block(nr, nc, k);
        }
        else if (a[nr][nc] == a[r][c] && !merged[nr][nc] && !merged[r][c]) {
            a[nr][nc] += a[r][c];
            a[r][c] = 0;
            merged[nr][nc] = 1;
            push_block(nr, nc, k);
        }
    }
}

void push(int k) {
    memset(merged, 0, sizeof(merged));
    if (k == 0) {
        for (int i=0;i<N;++i) {
            for (int j=N-1;j>=0;--j) {
                push_block(i, j, 0);
            }
        }
    }
    else if (k == 1) {
        for (int i=0;i<N;++i) {
            for (int j=0;j<N;++j) {
                push_block(i, j, 1);
            }
        }
    }
    else if (k == 2) {
        for (int i=N-1;i>=0;--i) {
            for (int j=0;j<N;++j) {
                push_block(i, j, 2);
            }
        }
    }
    else {
        for (int i=0;i<N;++i) {
            for (int j=0;j<N;++j) {
                push_block(i, j, 3);
            }
        }
    }
}

void dfs(int depth) {
    if (depth == 5) {
        for (int i=0;i<N;++i)
            for (int j=0;j<N;++j) ans = max(ans, a[i][j]);
        return;
    }
    vector<vector<int>> b = a;
    for (int k=0;k<4;++k) {
        push(k);
        dfs(depth+1);
        a = b;
    }
}

int main() {
    scanf("%d", &N);
    a.assign(N, vector<int>(N));
    for (int i=0;i<N;++i)
        for (int j=0;j<N;++j) scanf("%d", &a[i][j]);
    dfs(0);
    printf("%d", ans);
}

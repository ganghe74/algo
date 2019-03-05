#include <iostream>
using namespace std;
int M, N, K;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool field[50][50];
void dfs(int r, int c) {
    field[r][c] = false;
    for (int k=0;k<4;++k) {
        int ny = r + dy[k];
        int nx = c + dx[k];
        if (0 <= ny && ny < N && 0 <= nx && nx < M) {
            if (field[ny][nx]) {
                dfs(ny, nx);
            }
        }
    }
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int bug = 0;
        scanf("%d%d%d", &M, &N, &K);
        while (K--) {
            int r, c;
            scanf("%d%d", &c, &r);
            field[r][c] = true;
        }
        for (int i=0;i<N;++i) {
            for (int j=0;j<M;++j) {
                if (field[i][j]) {
                    dfs(i, j);
                    bug++;
                }
            }
        }
        printf("%d\n", bug);
    }
}
#include <cstdio>
#include <queue>
using namespace std;
int main() {
    int N, M;
    int a[100][100];
    int d[100][100];
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    scanf("%d %d", &N, &M);
    for (int i=0;i<N; i++) {
        for (int j=0;j<M; j++) {
            scanf("%1d", &a[i][j]);
        }
    }

    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    d[0][0] = 1;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int k=0 ; k<4 ; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (a[nx][ny] == 1 && d[nx][ny] == 0) {
                    q.push(make_pair(nx,ny));
                    d[nx][ny] = d[x][y] + 1;
                }
            }
        }
    }
    printf("%d\n", d[N-1][M-1]);
    return 0;
}
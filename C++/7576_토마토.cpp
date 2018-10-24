#include <iostream>
#include <queue>
using namespace std;

int N, M;
int a[1000][1000];
int d[1000][1000];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
queue<pair<int,int>> q;

void bfs(int x, int y) {
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int k=0;k<4;++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (a[nx][ny] == 0 && d[nx][ny] == 0) {
                    d[nx][ny] = d[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int main() {
    scanf("%d %d", &M, &N);
    for (int i=0;i<N;++i) {
        for (int j=0;j<M;++j) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i=0;i<N;++i) {
        for (int j=0;j<M;++j) {
            if (a[i][j] == 1 && d[i][j] == 0) {
                q.push(make_pair(i,j));
            }
        }
    }

    bfs(q.front().first, q.front().second);

    int result = -1;
    bool exit = false;
    for (int i=0;i<N;++i) {
        for (int j=0;j<M;++j) {
            if (a[i][j] == 0 && d[i][j] == 0) {
                result = -1;
                exit = true;
                break;
            }
            if (result < d[i][j]) {
                result = d[i][j];
            }
        }
        if (exit == true) break;
    }
    printf("%d\n", result);
}
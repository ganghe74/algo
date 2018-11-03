#include <iostream>
#include <queue>
using namespace std;
int N;
int a[100][100];
int d[100][100];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
queue<pair<int,int>> q;

void grouping(int x, int y, int cnt) {
    a[x][y] = cnt;
    for (int k=0;k<4;++k) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx >= 0 && nx < N && ny >= 0 && ny < N){
            if (a[nx][ny] == -1) {
                grouping(nx, ny, cnt);
            }
        }
    }
}

int main() {
    scanf("%d", &N);
    for (int i=0;i<N;++i) {
        for (int j=0;j<N;++j) {
            scanf("%d", &a[i][j]);
            if (a[i][j] == 1) {
                a[i][j] = - 1;
                q.push(make_pair(i,j));
            }
        }
    }
    
    int cnt = 0;
    for (int i=0;i<N;++i) {
        for (int j=0;j<N;++j) {
            if (a[i][j] == -1) grouping(i, j, ++cnt);
        }
    }

    int result = q.size() <= 1 ? 0 : 987654321;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int k=0;k<4;++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                if (a[nx][ny] == 0 && d[nx][ny] == 0) {
                    a[nx][ny] = a[x][y];
                    d[nx][ny] = d[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
                else if (a[nx][ny] != a[x][y]) {
                    int distance = d[nx][ny] + d[x][y];
                    if (result > distance) result = distance;
                }
            }
        }
    }
    printf("%d", result);
}
#include <iostream>
#include <algorithm>
using namespace std;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int a[25][25];
int d[25][25];
int answer[25*25];
int N;

void dfs(int x, int y, int cnt) {
    d[x][y] = cnt;
    for (int k=0;k<4;++k) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx >= 0 && nx < N && ny >=0 && ny < N) {
            if (a[nx][ny] == 1 && d[nx][ny] == 0) {
                dfs(nx, ny, cnt);
            }
        }
    }
}

int main() {
    cin >> N;
    for (int i=0;i<N;++i) {
        for (int j=0;j<N;++j) {
            scanf("%1d", &a[i][j]);
        }
    }

    int cnt = 0;
    for (int i=0;i<N;++i) {
        for (int j=0;j<N;++j) {
            if (a[i][j] == 1 && d[i][j] == 0) {
                dfs(i, j, ++cnt);
            }
        }
    }

    for (int i=0;i<N;++i) {
        for (int j=0;j<N;++j) {
            answer[d[i][j]] += 1;
        }
    }

    sort(answer+1, answer+cnt+1);

    cout << cnt << endl;
    for (int i=1;i<cnt+1;++i) {
        cout << answer[i] << endl;
    }
}
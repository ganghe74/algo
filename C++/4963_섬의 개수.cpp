#include <iostream>
#include <cstring>
using namespace std;

int w, h;
int a[50][50];
int d[50][50];
int dx[8] = {0,0,1,1,1,-1,-1,-1};
int dy[8] = {1,-1,1,0,-1,1,0,-1};

void dfs(int y, int x, int cnt) {
    d[y][x] = cnt;
    for (int k=0;k<8;++k) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx >= 0 && nx < w && ny >= 0 && ny < h) {
            if (a[ny][nx] == 1 && d[ny][nx] == 0) {
                dfs(ny, nx, cnt);
            }
        }
    }
}

int main() {
    cin >> w >> h;
    while (w != 0 || h != 0) {
        int cnt = 0;
        for (int i=0;i<h;++i) {
            for (int j=0;j<w;++j) {
                scanf("%1d", &a[i][j]);
            }
        }

        for (int i=0;i<h;++i) {
            for (int j=0;j<w;++j) {
                if (a[i][j] == 1 && d[i][j] == 0) {
                    dfs(i, j, ++cnt);
                }
            }
        }

        cout << cnt << endl;
        memset(a, 0, sizeof(a));
        memset(d, 0, sizeof(d));

        cin >> w >> h;
    }
}
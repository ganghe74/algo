#include <iostream>
#include <queue>
using namespace std;
int M, N, H;
int a[100][100][100], d[100][100][100];

const int dx[6] = {0,0,0,0,1,-1};
const int dy[6] = {0,0,1,-1,0,0};
const int dz[6] = {1,-1,0,0,0,0};

struct xyz {
    int x,y,z;
};

int main() {
    scanf("%d%d%d", &M, &N, &H);
    for (int h=0;h<H;++h) {
        for (int n=0;n<N;++n) {
            for (int m=0;m<M;++m) scanf("%d", &a[h][n][m]);
        }
    }

    queue<xyz> q;

    for (int z=0;z<H;++z) {
        for (int y=0;y<N;++y) {
            for (int x=0;x<M;++x) {
                if (a[z][y][x] == 1)
                    q.push({x,y,z});
            }
        }
    }

    while (!q.empty()) {
        xyz now = q.front();
        q.pop();
        for (int k=0;k<6;++k) {
            int nx = now.x + dx[k];
            int ny = now.y + dy[k];
            int nz = now.z + dz[k];
            if (0 <= nx && nx < M && 0 <= ny && ny < N && 0 <= nz && nz < H) {
                if (a[nz][ny][nx] == 0) {
                    a[nz][ny][nx] = 1;
                    d[nz][ny][nx] = d[now.z][now.y][now.x] + 1;
                    q.push({nx,ny,nz});
                }
            }
        }
    }

    int ans = 0;
    bool ok = true;
    
    for (int z=0;z<H;++z) {
        for (int y=0;y<N;++y) {
            for (int x=0;x<M;++x) {
                if (a[z][y][x] == 0) ok = false;
                ans = max(ans, d[z][y][x]);
            }
        }
    }

    if (ok) printf("%d", ans);
    else printf("-1");

}
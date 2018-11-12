#include <iostream>
#include <queue>
using namespace std;

int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};

int main() {
    int N, M, answer = 0;
    int a[100][100];
    scanf("%d %d", &N, &M);
    for (int i=0;i<N;++i) {
        for (int j=0;j<M;++j) scanf("%d", &a[i][j]);
    }
    for (int h=1;h<=10000;++h) {
        int floor[102][102] = {0};
        for (int i=0;i<N;++i) {
            for (int j=0;j<M;++j) {
                if (a[i][j] >= h) floor[i+1][j+1] = 1;
            }
        }
        queue<pair<int, int>> q;
        q.push(make_pair(0,0));
        while(!q.empty()) {
            for (int k=0;k<4;++k) {
                int ny = q.front().first + dy[k];
                int nx = q.front().second + dx[k];
                if (ny >= 0 && ny < N+2 && nx >= 0 && nx < M+2) {
                    if (floor[ny][nx] == 0) {
                        floor[ny][nx] = 1;
                        q.push(make_pair(ny, nx));
                    }
                }
            }
            q.pop();
        }
        for (int i=0;i<N+2;++i)
            for (int j=0;j<M+2;++j)
                if (floor[i][j] == 0) answer += 1;
    }
    printf("%d", answer);
}
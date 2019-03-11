#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int M, N, K;
bool a[101][101];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
void cover(int x1, int y1, int x2, int y2) {
    for (int y=y1;y<y2;++y) {
        for (int x=x1;x<x2;++x) a[y][x] = 1;
    }
}
int dfs(int x, int y) {
    a[y][x] = 1;
    int ret = 1;
    for (int k=0;k<4;++k) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (0 <= nx && nx < N && 0 <= ny && ny < M) {
            if (!a[ny][nx]) ret += dfs(nx, ny);
        }
    }
    return ret;
}
int main() {
    scanf("%d%d%d", &M, &N, &K);
    for (int i=0;i<K;++i) {
        int x1, x2, y1, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        cover(x1, y1, x2, y2);
    }
    int cnt = 0;
    vector<int> ans;
    for (int i=0;i<M;++i) {
        for (int j=0;j<N;++j) {
            if (!a[i][j]) {
                ans.push_back(dfs(j,i));
                cnt++;
            }
        }
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", cnt);
    for (auto n : ans) printf("%d ", n);
}
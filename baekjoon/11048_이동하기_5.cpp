#include <iostream>
#include <cstring>
using namespace std;
int a[1001][1001], d[1001][1001];
int N, M;
int go(int x, int y) {
    if (x > N || y > M) return 0;
    if (d[x][y] >= 0) return d[x][y];
    d[x][y] = go(x+1,y) + a[x][y];
    int temp = go(x,y+1) + a[x][y];
    if (d[x][y] < temp)
        d[x][y] = temp;
    return d[x][y];
}

int main() {
    memset(d, -1, sizeof(d));
    scanf("%d%d", &N, &M);
    for (int i=1;i<=N;++i) {
        for (int j=1;j<=M;++j) scanf("%d", &a[i][j]);
    }
    printf("%d", go(1,1));
}
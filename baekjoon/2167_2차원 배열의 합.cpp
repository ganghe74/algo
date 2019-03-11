#include <iostream>
using namespace std;
int a[301][301], d[301][301];
int main() {
    int N, M, K;
    scanf("%d%d", &N, &M);
    for (int i=1;i<=N;++i) {
        int lineSum = 0;
        for (int j=1;j<=M;++j) {
            scanf("%d", &a[i][j]);
            lineSum += a[i][j];
            d[i][j] = d[i-1][j] + lineSum;
        }
    }
    scanf("%d", &K);
    while (K--) {
        int x1, x2, y1, y2;
        scanf("%d%d%d%d", &y1, &x1, &y2, &x2);
        printf("%d\n", d[y2][x2] - d[y1-1][x2] - d[y2][x1-1] + d[y1-1][x1-1]);
    }
}
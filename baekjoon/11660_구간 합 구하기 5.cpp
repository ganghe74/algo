#include <iostream>
using namespace std;

int N, M, x1, x2, y1, y2, a[1025][1025], d[1025][1025];

int main() {
    scanf("%d%d", &N, &M);
    for (int i=1;i<=N;++i) {
        for (int j=1;j<=N;++j) {
            scanf("%d", &a[i][j]);
            d[i][j] = d[i-1][j] + d[i][j-1] - d[i-1][j-1] + a[i][j];
        }
    }
    while (M--) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        printf("%d\n", d[x2][y2] - d[x1-1][y2] - d[x2][y1-1] + d[x1-1][y1-1]);
    }
}
#include <bits/stdc++.h>
using namespace std;

int N, a[1000][3], d[3][1000][3];

int main() {
    scanf("%d", &N);
    for (int i=0;i<N;++i) scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
    for (int i=0;i<3;++i)
        for (int j=0;j<3;++j) d[i][0][j] = 1e9;
    for (int i=0;i<3;++i) d[i][0][i] = a[0][i];
    for (int i=1;i<N;++i) {
        for (int j=0;j<3;++j) {
            d[j][i][0] = min(d[j][i-1][1], d[j][i-1][2]) + a[i][0];
            d[j][i][1] = min(d[j][i-1][0], d[j][i-1][2]) + a[i][1];
            d[j][i][2] = min(d[j][i-1][0], d[j][i-1][1]) + a[i][2];
        }
    }
    int ans = 1e9;
    for (int i=0;i<3;++i)
        for (int j=0;j<3;++j)
            if (i != j) ans = min(ans, d[i][N-1][j]);
    printf("%d", ans);
}

#include <iostream>
using namespace std;
int a[1002][1002], d[1002][1002];
int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i=1;i<=N;++i) {
        for (int j=1;j<=M;++j) scanf("%d", &a[i][j]);
    }
    for (int i=0;i<=N;++i) {
        for (int j=0;j<=M;++j) {
            if (d[i+1][j] < d[i][j] + a[i+1][j])
                d[i+1][j] = d[i][j] + a[i+1][j];
            if (d[i][j+1] < d[i][j] + a[i][j+1])
                d[i][j+1] = d[i][j] + a[i][j+1];
            if (d[i+1][j+1] < d[i][j] + a[i+1][j+1])
                d[i+1][j+1] = d[i][j] + a[i+1][j+1];
        }
    }
    printf("%d", d[N][M]);
}
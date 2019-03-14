#include <iostream>
#define REMAINDER 1000000000
using namespace std;
int a[101][10][1<<10];
int main() {
    int N, ans = 0;
    scanf("%d", &N);
    for (int i=1;i<10;++i) a[1][i][1<<i] = 1;
    for (int i=2;i<=N;++i) {
        for (int j=0;j<10;++j) {
            for (int k=0;k<(1<<10);++k) {
                if (j != 0) a[i][j][k | (1<<j)] += a[i-1][j-1][k]; a[i][j][k | (1<<j)] %= REMAINDER;
                if (j != 9) a[i][j][k | (1<<j)] += a[i-1][j+1][k]; a[i][j][k | (1<<j)] %= REMAINDER;
            }
        }
    }
    for (int i=0;i<10;++i) {
        ans += a[N][i][(1<<10)-1];
        ans %= REMAINDER;
    }
    printf("%d", ans);
}
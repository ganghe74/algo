#include <iostream>
using namespace std;
int a[1001][1001], d[1001][1001];
int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i=1;i<=N;++i) {
        for (int j=1;j<=M;++j) scanf("%d", &a[i][j]);
    }
    for (int i=1;i<=N;++i) {
        for (int j=1;j<=M;++j) d[i][j] = max(d[i-1][j], d[i][j-1]) + a[i][j];
    }
    printf("%d", d[N][M]);
}
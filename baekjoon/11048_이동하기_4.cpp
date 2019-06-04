#include <iostream>
#include <cstring>
using namespace std;
int a[1001][1001], d[1001][1001];

int go(int i, int j) {
    if (i == 1 && j == 1) return a[i][j];
    if (i < 1 || j < 1) return 0;
    if (d[i][j] >= 0) return d[i][j];
    d[i][j] = go(i-1,j) + a[i][j];
    int temp = go(i, j-1) + a[i][j];
    if (d[i][j] < temp) d[i][j] = temp;
    return d[i][j];
}
int main() {
    memset(d, -1, sizeof(d));
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i=1;i<=N;++i) {
        for (int j=1;j<=M;++j) scanf("%d", &a[i][j]);
    }
    printf("%d", go(N,M));
}
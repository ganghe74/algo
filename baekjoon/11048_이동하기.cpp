#include <iostream>
using namespace std;
int a[1000][1000];
int d[1000][1000];
int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i=0;i<N;++i) {
        for (int j=0;j<M;++j) scanf("%d", &a[i][j]);
    }
    d[0][0] = a[0][0];
    for (int i=1;i<M;++i) d[0][i] = d[0][i-1] + a[0][i];
    for (int i=1;i<N;++i) d[i][0] = d[i-1][0] + a[i][0];
    for (int i=1;i<N;++i) {
        for (int j=1;j<M;++j) {
            d[i][j] = max(max(d[i][j-1], d[i-1][j]), d[i-1][j-1]) + a[i][j];
        }
    }
    printf("%d", d[N-1][M-1]);
}
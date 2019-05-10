#include <iostream>
using namespace std;
int main() {
    int N, M, a[2][100][100];
    scanf("%d%d", &N, &M);
    for (int i=0;i<2;++i) {
        for (int j=0;j<N;++j) {
            for (int k=0;k<M;++k) scanf("%d", &a[i][j][k]);
        }
    }
    for (int i=0;i<N;++i) {
        for (int j=0;j<M;++j) printf("%d ", a[0][i][j] + a[1][i][j]);
        puts("");
    }
}
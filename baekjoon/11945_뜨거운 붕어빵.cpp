#include <iostream>
using namespace std;
int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    bool shape[N][M];
    for (int i=0;i<N;++i) {
        for (int j=0;j<M;++j) scanf("%1d", &shape[i][j]);
    }
    for (int i=0;i<N;++i) {
        for (int j=M-1;j>=0;--j) printf("%d", shape[i][j]);
        printf("\n");
    }
}
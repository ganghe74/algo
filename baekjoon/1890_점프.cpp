#include <iostream>
using namespace std;
long long a[100][100], d[100][100];
int main() {
    int N;
    scanf("%d", &N);
    for(int i=0;i<N;++i) {
        for (int j=0;j<N;++j) scanf("%lld", &a[i][j]);
    }
    d[0][0] = 1;
    for (int i=0;i<N;++i) {
        for (int j=0;j<N;++j) {
            for (int k=0;k<i;++k) {
                if (k + a[k][j] == i) d[i][j] += d[k][j];
            }
            for (int k=0;k<j;++k) {
                if (k + a[i][k] == j) d[i][j] += d[i][k];
            }
        }
    }
    printf("%lld", d[N-1][N-1]);
}
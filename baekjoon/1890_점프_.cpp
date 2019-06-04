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
            if (a[i][j] == 0) continue;
            if (j + a[i][j] < N) d[i][j+a[i][j]] += d[i][j];
            if (i + a[i][j] < N) d[i+a[i][j]][j] += d[i][j];
        }
    }
    printf("%lld", d[N-1][N-1]);
}
#include <bits/stdc++.h>
using namespace std;

int N, a[1001], d[501][500], num[501][500];

void trace(int n, int m) {
    if (!n) return;
    printf("%d ", num[n][m]);
    trace(n-1, (m-num[n][m]+N)%N);
}

int main() {
    memset(num, -1, sizeof(num));
    d[0][0] = 1;
    scanf("%d", &N);
    for (int i=1;i<=2*N-1;++i) scanf("%d", &a[i]);
    for (int i=1;i<=2*N-1;++i) {
        for (int l=min(i,N);l>0;--l) {
            for (int j=0;j<N;++j) {
                if (d[l-1][j]) {
                    if (num[l][(j+a[i])%N] == -1) num[l][(j+a[i])%N] = a[i];
                    d[l][(j+a[i])%N] += d[l-1][j];
                }
            }
        }
    }
    if (d[N][0]) trace(N, 0);
    else puts("-1");
}

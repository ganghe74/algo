#include <bits/stdc++.h>
using namespace std;

int N, M, K, d[201][201];

int main() {
    scanf("%d%d%d", &N, &M, &K);
    d[0][0] = 1;
    for (int i=1;i<=N+M;++i)
        for (int j=0;j<=i;++j) {
            if (i-j) d[i-j][j] += d[i-j-1][j];
            if (j) d[i-j][j] += d[i-j][j-1];
            d[i-j][j] = min(d[i-j][j], int(1e9));
        }
    if (K > d[N][M]) puts("-1");
    else {
        while (N + M) {
            if (!N || K > d[N-1][M]) {
                putchar('z');
                K -= d[N-1][M];
                M--;
            }
            else {
                putchar('a');
                N--;
            }
        }
    }
}

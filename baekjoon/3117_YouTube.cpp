#include <bits/stdc++.h>
using namespace std;

int N, K, M, a[100001], f[30][100001];

int main() {
    scanf("%d%d%d", &N, &K, &M);
    for (int i=0;i<N;++i) scanf("%d", &a[i]);
    for (int i=1;i<=K;++i) scanf("%d", &f[0][i]);
    for (int i=1;i<30;++i)
        for (int j=1;j<=K;++j)
            f[i][j] = f[i-1][f[i-1][j]];
    for (int i=0;i<N;++i) {
        int video = a[i];
        int r = M-1;
        for (int i=29;i>=0;--i) {
            if (r >= 1<<i) {
                video = f[i][video];
                r -= 1<<i;
            }
        }
        printf("%d ", video);
    }
}

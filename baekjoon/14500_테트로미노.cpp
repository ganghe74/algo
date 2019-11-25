#include <bits/stdc++.h>
using namespace std;

int N, M, ans, a[500][500];

int main() {
    scanf("%d%d", &N, &M);
    for (int i=0;i<N;++i)
        for (int j=0;j<M;++j) scanf("%d", &a[i][j]);
    for (int i=0;i<N-1;++i)
        for (int j=0;j<M-1;++j)
            ans = max(ans, a[i][j] + a[i][j+1] + a[i+1][j] + a[i+1][j+1]);
    for (int i=0;i<N-3;++i)
        for (int j=0;j<M;++j)
            ans = max(ans, a[i][j] + a[i+1][j] + a[i+2][j] + a[i+3][j]);
    for (int i=0;i<N;++i)
        for (int j=0;j<M-3;++j)
            ans = max(ans, a[i][j] + a[i][j+1] + a[i][j+2] + a[i][j+3]);
    for (int i=0;i<N-1;++i)
        for (int j=0;j<M-2;++j)
            ans = max({
                ans,
                a[i][j] + a[i][j+1] + a[i][j+2] + max({a[i+1][j], a[i+1][j+1], a[i+1][j+2]}),
                a[i+1][j] + a[i+1][j+1] + a[i+1][j+2] + max({a[i][j], a[i][j+1], a[i][j+2]}),
                a[i][j] + a[i][j+1] + a[i+1][j+1] + a[i+1][j+2],
                a[i+1][j] + a[i+1][j+1] + a[i][j+1] + a[i][j+2]
            });
    for (int i=0;i<N-2;++i)
        for (int j=0;j<M-1;++j)
            ans = max({
                ans,
                a[i][j] + a[i+1][j] + a[i+2][j] + max({a[i][j+1], a[i+1][j+1], a[i+2][j+1]}),
                a[i][j+1] + a[i+1][j+1] + a[i+2][j+1] + max({a[i][j], a[i+1][j], a[i+2][j]}),
                a[i][j] + a[i+1][j] + a[i+1][j+1] + a[i+2][j+1],
                a[i][j+1] + a[i+1][j+1] + a[i+1][j] + a[i+2][j]
            });
    printf("%d", ans);
}
#include <bits/stdc++.h>
using namespace std;

int N, M, u, v, ans, d[501][501];

int main() {
    scanf("%d%d", &N, &M);
    for (int i=1;i<=N;++i)
        for (int j=1;j<=N;++j)
            d[i][j] = (i == j) ? 0 : 1e9;
    while (M--) {
        scanf("%d%d", &u, &v);
        d[u][v] = 1;
    }
    for (int k=1;k<=N;++k)
        for (int i=1;i<=N;++i)
            for (int j=1;j<=N;++j)
                if (d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];
    for (int i=1;i<=N;++i) {
        int cnt = 0;
        for (int j=1;j<=N;++j)
            if (d[j][i] < 1e9 || d[i][j] < 1e9) cnt++;
        if (cnt == N) ans++;
    }
    printf("%d", ans);
}

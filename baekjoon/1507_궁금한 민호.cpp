#include <bits/stdc++.h>
using namespace std;
int N, ans, d[20][20];
bool unused[20][20];
int main() {
    scanf("%d", &N);
    for (int i=0;i<N;++i)
        for (int j=0;j<N;++j) scanf("%d", &d[i][j]);
    for (int k=0;k<N;++k) {
        for (int i=0;i<N;++i) {
            if (i == k) continue;
            for (int j=0;j<N;++j) {
                if (i == j || j == k) continue;
                if (d[i][j] > d[i][k] + d[k][j]) {
                    puts("-1");
                    return 0;
                }
                if (d[i][j] == d[i][k] + d[k][j]) unused[i][j] = 1;
            }
        }
    }
    for (int i=0;i<N;++i)
        for (int j=0;j<N;++j)
            if (!unused[i][j]) ans += d[i][j];
    printf("%d", ans/2);
}
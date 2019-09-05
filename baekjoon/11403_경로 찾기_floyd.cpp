#include <bits/stdc++.h>
using namespace std;
int d[100][100];
int main() {
    int N;
    scanf("%d", &N);
    for (int i=0;i<N;++i) {
        for (int j=0;j<N;++j) scanf("%d", &d[i][j]);
    }
    for (int k=0;k<N;++k) {
        for (int i=0;i<N;++i) {
            for (int j=0;j<N;++j) {
                if (d[i][k] != 0 && d[k][j] != 0) {
                    if (d[i][j] == 0) d[i][j] = d[i][k]+d[k][j];
                    else d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }
    for (int i=0;i<N;++i) {
        for (int j=0;j<N;++j) printf("%d ", min(1,d[i][j]));
        puts("");
    }
}
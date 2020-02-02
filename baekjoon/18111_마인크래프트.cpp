#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, B, a[500][500];
    scanf("%d%d%d", &N, &M, &B);
    for (int i=0;i<N;++i)
        for (int j=0;j<M;++j) scanf("%d", &a[i][j]);
    int mint = 1e9, minh = 0;
    for (int h=256;h>=0;--h) {
        int b = B;
        int t = 0;
        for (int i=0;i<N;++i) {
            for (int j=0;j<M;++j) {
                if (a[i][j] > h) {
                    b += a[i][j] - h;
                    t += (a[i][j] - h) * 2;
                }
                else {
                    b -= h - a[i][j];
                    t += h - a[i][j];
                }
            }
        }
        if (b >= 0 && t < mint) {
            mint = t;
            minh = h;
        }
    }
    printf("%d %d", mint, minh);
}
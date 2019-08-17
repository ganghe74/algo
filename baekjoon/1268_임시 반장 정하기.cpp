#include <bits/stdc++.h>
using namespace std;
int a[1000][5];
int main() {
    int N;
    scanf("%d", &N);
    for (int i=0;i<N;++i) {
        for (int j=0;j<5;++j) scanf("%d", &a[i][j]);
    }
    int M = 0, Mw = 0;
    for (int i=0;i<N;++i) {
        int w = 0;
        for (int j=0;j<N;++j) {
            for (int k=0;k<5;++k) {
                if (a[i][k] == a[j][k]) {
                    w++;
                    break;
                }
            }
            if (w > Mw) {
                M = i;
                Mw = w;
            }
        }
    }
    printf("%d", M+1);
}
#include <bits/stdc++.h>
using namespace std;

int d[1005][1005];

int main() {
    d[0][0] = 1;
    for (int i=0;i<1000;++i) {
        for (int j=0;j<=i;++j) {
            d[i+1][j] += d[i][j];
            d[i+1][j+1] += d[i][j];
        }
    }
    for (int i=0;i<100;++i) {
        for (int j=0;j<=i;++j) printf("%d ", d[i][j]);
        puts("");
    }
}
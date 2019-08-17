#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

lint d[32][33];

int main() {
    fill(d[0], d[0]+32, 1);
    for (int i=0;i<31;++i) {
        for (int j=0;j<32;++j) {
            d[i+1][j] += d[i][j];
            d[i+1][j+1] += d[i][j];
        }
    }
    lint N, L, I;
    scanf("%lld%lld%lld", &N, &L, &I);
    while (N > 0) {
        if (I > d[N-1][L]) {
            putchar('1');
            I -= d[N-1][L];
            L--;
        }
        else {
            putchar('0');
        }
        N--;
    }
}
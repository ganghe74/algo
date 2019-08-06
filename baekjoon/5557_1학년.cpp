#include <bits/stdc++.h>
using namespace std;

int N, a[100];
long long d[101][21];

int main() {
    scanf("%d", &N);
    for (int i=0;i<N;++i) scanf("%d", &a[i]);
    d[0][a[0]] = 1;
    for (int i=0;i<N-2;++i) {
        for (int j=0;j<=20;++j) {
            if (d[i][j] > 0) {
                if (j + a[i+1] <= 20) d[i+1][j+a[i+1]] += d[i][j];
                if (j - a[i+1] >= 0) d[i+1][j-a[i+1]] += d[i][j];
            }
        }
    }
    printf("%lld", d[N-2][a[N-1]]);
}
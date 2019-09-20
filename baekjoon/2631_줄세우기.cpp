#include <bits/stdc++.h>
using namespace std;
int N, M, a[200], d[200];
int main() {
    scanf("%d", &N);
    for (int i=0;i<N;++i) scanf("%d", &a[i]);
    for (int i=0;i<N;++i) {
        d[i] = 1;
        for (int j=0;j<i;++j) {
            if (a[i] > a[j] && d[i] < d[j] + 1) d[i] = d[j] + 1;
        }
        M = max(M, d[i]);
    }
    printf("%d", N-M);
}
#include <bits/stdc++.h>
using namespace std;
int N, M, x, d[1000001];
int main() {
    scanf("%d", &N);
    for (int i=0;i<N;++i) {
        scanf("%d", &x);
        d[x] = d[x-1] + 1;
        M = max(M, d[x]);
    }
    printf("%d", N-M);
}
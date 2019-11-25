#include <bits/stdc++.h>
using namespace std;

int N, M, x, d[100001];

int main() {
    scanf("%d%d", &N, &M);
    for (int i=1;i<=N;++i) {
        scanf("%d", &x);
        d[i] = d[i-1] + x;
    }
    while (M--) {
        int i, j;
        scanf("%d%d", &i, &j);
        printf("%d\n", d[j]-d[i-1]);
    }
}
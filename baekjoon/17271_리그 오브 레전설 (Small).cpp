#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e+9 + 7;
int d[10001];
int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    d[0] = 1;
    for (int i=1;i<M;++i) d[i] = 1;
    for (int i=M;i<=N;++i) d[i] = (d[i-M] + d[i-1]) % MOD;
    // for (int i=1;i<=N;++i) printf("%d ", d[i]);
    // puts("");
    printf("%d", d[N]);
}
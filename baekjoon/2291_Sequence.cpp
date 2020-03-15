#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int N, M, K;
lint d[11][221][221];

lint solve(int N, int M, int lo) {
    if (lo*N > M) return 0;
    if (N <= 1) return N;
    lint &ret = d[N][M][lo];
    if (ret != -1) return ret;
    ret = 0;
    for (int i=lo;i*(N-1)<=(M-i);++i) {
        ret += solve(N-1, M-i, i);
    }
    ret = min(ret, (lint)1e10);
    return ret;
}

int main() {
    memset(d, -1, sizeof(d));
    scanf("%d%d%d", &N, &M, &K);
    int lo = 1;
    while (N--) {
        if (N) {
            for (int i=lo;i<=M;++i) {
                if (K > solve(N, M-i, i))
                    K -= solve(N, M-i, i);
                else {
                    printf("%d ", i);
                    M -= i;
                    lo = i;
                    break;
                }
            }
        }
        else printf("%d ", M);
    }
}

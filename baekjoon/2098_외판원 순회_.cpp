#include <bits/stdc++.h>
using namespace std;
int N, a[16][16], d[16][1<<16];

int solve(int now, int status) {
    int &ret = d[now][status];
    if (ret) return ret;
    if (status == (1 << N)-1 && a[now][0]) return ret = a[now][0];
    ret = 1e9;
    for (int i=0;i<N;++i) {
        if (!(status & (1 << i)) && a[now][i])
            ret = min(ret, solve(i, status | (1 << i)) + a[now][i]);
    }
    return ret;
}

int main() {
    scanf("%d", &N);
    for (int i=0;i<N;++i)
        for (int j=0;j<N;++j) scanf("%d", &a[i][j]);
    printf("%d", solve(0, 1));
}
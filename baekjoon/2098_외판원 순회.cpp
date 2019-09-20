#include <bits/stdc++.h>
using namespace std;
int N, a[16][16], d[16][16][1<<16];

int solve(int start, int now, int status) {
    int &ret = d[start][now][status];
    if (ret != -1) return ret;
    if (status == (1 << N)-1 && a[now][start]) return ret = a[now][start];
    ret = 1e9;
    for (int i=0;i<N;++i) {
        if (!(status & (1 << i)) && a[now][i])
            ret = min(ret, solve(start, i, status | (1 << i)) + a[now][i]);
    }
    return ret;
}

int main() {
    memset(d, -1, sizeof(d));
    scanf("%d", &N);
    for (int i=0;i<N;++i)
        for (int j=0;j<N;++j) scanf("%d", &a[i][j]);
    int m = 1e9;
    for (int i=0;i<N;++i) m = min(m, solve(i,i,(1 << i)));
    printf("%d", m);
}
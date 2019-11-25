#include <bits/stdc++.h>
using namespace std;

int N, M, K, a[300][300];

void f(int r, int c, int n, int m) {
    if (n == 0 || m == 0) return;
    for (int i=c+1;i<c+m;++i) swap(a[r][i], a[r][i-1]);
    for (int i=r+1;i<r+n;++i) swap(a[i][c+m-1], a[i-1][c+m-1]);
    for (int i=c+m-1;i>c;--i) swap(a[r+n-1][i], a[r+n-1][i-1]);
    for (int i=r+n-1;i>r+1;--i) swap(a[i][c], a[i-1][c]);
    f(r+1, c+1, n-2, m-2);
}

int main() {
    scanf("%d%d%d", &N, &M, &K);
    for (int i=0;i<N;++i)
        for (int j=0;j<M;++j) scanf("%d", &a[i][j]);
    while (K--) f(0,0,N,M);
    for (int i=0;i<N;++i) {
        for (int j=0;j<M;++j) printf("%d ", a[i][j]);
        puts("");
    }
}
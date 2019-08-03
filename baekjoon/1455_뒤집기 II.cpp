#include <bits/stdc++.h>
using namespace std;

int a[100][100], cnt;

void turn(int r, int c) {
    cnt++;
    for (int i=0;i<=r;++i) {
        for (int j=0;j<=c;++j) a[i][j] = !a[i][j];
    }
}

void f(int r, int c) {
    for (int i=c;i>=0;--i) {
        if (a[r][i]) turn(r, i);
    }
    for (int i=r;i>=0;--i) {
        if (a[i][c]) turn(i, c);
    }
}

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i=0;i<N;++i) {
        for (int j=0;j<M;++j) scanf("%1d", &a[i][j]);
    }
    while (N >= 0 && M >= 0) {
        f(N, M);
        N--; M--;
    }
    printf("%d", cnt);
}
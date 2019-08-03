#include <bits/stdc++.h>
using namespace std;

int N, cnt[2];
int a[128][128];

void solve(int r, int c, int size) {
    int color = a[r][c];
    if (size == 1) {
        cnt[color]++;
        return;
    }
    bool ok = true;
    for (int i=r;i<r+size;++i) {
        for (int j=c;j<c+size;++j) {
            if (a[i][j] != color) {
                ok = false;
                break;
            }
        }
        if (!ok) break;
    }
    if (ok) cnt[color]++;
    else {
        solve(r, c, size/2);
        solve(r, c+size/2, size/2);
        solve(r+size/2, c, size/2);
        solve(r+size/2, c+size/2, size/2);
    }
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i=0;i<N;++i) {
        for (int j=0;j<N;++j) scanf("%d", &a[i][j]);
    }
    solve(0, 0, N);
    printf("%d\n%d", cnt[0], cnt[1]);
}
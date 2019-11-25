#include <bits/stdc++.h>
using namespace std;

int n, a[1000][1000];

void Eulerian(int now) {
    for (int i=0;i<n;++i) {
        if (a[now][i]) {
            a[now][i]--;
            a[i][now]--;
            Eulerian(i);
        }
    }
    printf("%d ", now+1);
}

int main() {
    scanf("%d", &n);
    for (int i=0;i<n;++i)
        for (int j=0;j<n;++j) scanf("%d", &a[i][j]);
    for (int i=0;i<n;++i) {
        int cnt = 0;
        for (int j=0;j<n;++j) cnt += a[i][j];
        if (cnt & 1) {
            puts("-1");
            return 0;
        }
    }
    Eulerian(0);
}
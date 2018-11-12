#include <bits/stdc++.h>
#define max(a,b) ((a>b)?a:b)
using namespace std;

int n;
int a[500][500];
int d[500][500];

int path(int y, int x) {
    if (y==n) return 0;
    int& ret = d[y][x];
    if (ret != -1) return ret;
    ret = max(path(y+1, x), path(y+1, x+1)) + a[y][x];
    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i=0;i<n;++i) {
        for (int j=0;j<=i;++j) {
            scanf("%d", &a[i][j]);
        }
    }
    memset(d, -1, sizeof(d));
    printf("%d", path(0,0));
}
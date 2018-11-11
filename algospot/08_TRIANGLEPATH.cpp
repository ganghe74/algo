#include <iostream>
#include <cstring>
#define max(a,b) ((a>b)?a:b)
using namespace std;

int a[100][100];
int d[100][100];
int C, n;

int solve(int y, int x) {
    if (y == n-1) return a[y][x];
    int& ret = d[y][x];
    if (ret != -1) return d[y][x];
    return ret = a[y][x] + max(solve(y+1,x), solve(y+1, x+1));
}

int main() {
    scanf("%d", &C);
    while (C--) {
        memset(d,-1,sizeof(d));
        scanf("%d", &n);
        for (int i=0;i<n;++i) {
            for (int j=0;j<=i;++j) {
                scanf("%d", &a[i][j]);
            }
        }
        printf("%d\n", solve(0,0));
    }
}
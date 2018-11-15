#include <iostream>
#include <cstring>
#define max(a,b) ((a>b)?a:b)
using namespace std;

int a[100][100];
int d[100][100];
int countCache[100][100];
int C, n;

int solve(int y, int x) {
    if (y == n-1) return a[y][x];
    int& ret = d[y][x];
    if (ret != -1) return d[y][x];
    return ret = a[y][x] + max(solve(y+1,x), solve(y+1, x+1));
}

int count(int y, int x) {
    if (y == n-1) return 1;
    int& ret = countCache[y][x];
    if(ret != -1) return ret;
    ret = 0;
    if (solve(y+1, x+1) >= solve(y+1, x)) ret += count(y+1, x+1);
    if (solve(y+1, x+1) <= solve(y+1, x)) ret += count(y+1, x);
    return ret;
}

int main() {
    scanf("%d", &C);
    while (C--) {
        memset(d, -1, sizeof(d));
        memset(countCache, -1, sizeof(countCache));
        scanf("%d", &n);
        for (int i=0;i<n;++i) {
            for (int j=0;j<=i;++j) {
                scanf("%d", &a[i][j]);
            }
        }
        solve(0,0);
        printf("%d\n", count(0,0));
    }
}
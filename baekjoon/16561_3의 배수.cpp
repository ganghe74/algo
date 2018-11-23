#include <bits/stdc++.h>
using namespace std;

int d[1001][3];

int solve(int x, int count) {
    if (count == 3) return 1; 
    int ret = d[x][count-1];
    if (ret != -1) return ret;
    ret = 0;
    for (int i=1;i<=x-(3-count);++i) {
        ret += solve(x-i, count+1);
    }
    return ret;
}

int main() {
    memset(d, -1, sizeof(d));
    int n;
    scanf("%d", &n);
    n /= 3;
    printf("%d", solve(n, 1));
}
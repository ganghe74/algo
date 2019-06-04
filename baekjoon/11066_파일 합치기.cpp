#include <bits/stdc++.h>
using namespace std;
int a[501], s[501], d[501][501];
int go(int i, int j) {
    if (i == j) return 0;
    if (d[i][j] != -1) return d[i][j];
    for (int k=i;k<j;++k) {
        int temp = go(i,k) + go(k+1,j) + s[j] - s[i-1];
        if (d[i][j] == -1 || temp < d[i][j]) {
            d[i][j] = temp;
        }
    }
    return d[i][j];
}
int main() {
    int T, K;
    scanf("%d", &T);
    while (T--) {
        memset(d, -1, sizeof(d));
        memset(s, 0, sizeof(s));
        scanf("%d", &K);
        for (int i=1;i<=K;++i) {
            scanf("%d", &a[i]);
            s[i] = s[i-1] + a[i];
        }
        printf("%d\n", go(1, K));
    }
}
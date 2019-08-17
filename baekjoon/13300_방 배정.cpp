#include <bits/stdc++.h>
using namespace std;
int a[2][6];
int main() {
    int n, k, s, y, ans = 0;
    scanf("%d%d", &n, &k);
    while (n--) {
        scanf("%d%d", &s, &y);
        a[s][y-1]++;
    }
    for (int i=0;i<2;++i) {
        for (int j=0;j<6;++j) ans += (a[i][j] + k-1) / k;
    }
    printf("%d", ans);
}
#include <bits/stdc++.h>
using namespace std;
int a[1001], d[1001];
int main() {
    int n, ans = 0;
    scanf("%d", &n);
    for (int i=1;i<=n;++i) scanf("%d", &a[i]);
    for (int i=1;i<=n;++i) {
        d[i] = 1;
        for (int j=1;j<i;++j) {
            if (a[i] > a[j]) {
                d[i] = max(d[i], d[j] + 1);
            }
        }
        ans = max(ans, d[i]);
    }
    printf("%d", ans);
}
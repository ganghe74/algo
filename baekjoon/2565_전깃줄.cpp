#include <bits/stdc++.h>
using namespace std;
int a[501], d[501];
int main() {
    for (int i=0;i<=500;++i) a[i] = 1e9;
    int N, x, y, ans = 0;
    scanf("%d", &N);
    for (int i=0;i<N;++i) {
        scanf("%d%d", &x, &y);
        a[x] = y;
    }
    for (int i=0;i<=500;++i) {
        for (int j=0;j<i;++j) {
            if (a[i] > a[j]) {
                d[i] = max(d[i], d[j]+1);
                ans = max(ans, d[i]);
            }
        }
    }
    printf("%d", N - ans);
}
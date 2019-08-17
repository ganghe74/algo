#include <bits/stdc++.h>
using namespace std;
int a[101];
int main() {
    int A, B, C, b, e, ans = 0;
    scanf("%d%d%d", &A, &B, &C);
    for (int i=0;i<3;++i) {
        scanf("%d%d", &b, &e);
        for (int t=b;t<e;++t) a[t]++;
    }
    for (int i=0;i<101;++i) {
        if (a[i] == 1) ans += A;
        if (a[i] == 2) ans += 2*B;
        if (a[i] == 3) ans += 3*C;
    }
    printf("%d", ans);
}
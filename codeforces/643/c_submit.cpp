#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    int A, B, C, D;
    scanf("%d%d%d%d", &A, &B, &C, &D);
    lint ans = 0;
    for (int x=A; x<=B; ++x) {
        int y = max(B, C-x+1);
        int n1 = min(x+y-1, D) - C + 1;
        int y2 = min(max(y, D-x+1), C);
        int n2 = min(x+y2-1, D) - C + 1;

        lint d = 1LL * n2 * (n2+1) / 2 - 1LL * (n1-1) * n1 / 2;

        if (y2 + 1 <= C) {
            d += 1LL * (C - (y2+1) + 1) * (D-C+1);
        }
        ans += d;
    }
    printf("%lld", ans);
}

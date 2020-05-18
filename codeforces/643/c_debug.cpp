#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    int A, B, C, D;
    scanf("%d%d%d%d", &A, &B, &C, &D);

    lint ans = 0;

    // search for all pair (x, y) (TLE)
    for (int x=A; x<=B; ++x) {
        for (int y=max(B,C-x+1); y<=C; ++y) {
            // printf("x %d y %d - %d\n", x, y, min(x+y-1, D) - C + 1);
            ans += min(x+y-1, D) - C + 1;
        }
    }
    printf("%lld", ans);
    puts("");

    // search for all x
    ans = 0;
    for (int x=A; x<=B; ++x) {
        int y = max(B, C-x+1);
        int n1 = min(x+y-1, D) - C + 1;
        int y2 = min(max(y, D-x+1), C);
        int n2 = min(x+y2-1, D) - C + 1;

        lint d = 1LL * n2 * (n2+1) / 2 - 1LL * (n1-1) * n1 / 2;
        // ans += 1LL * n2 * (n2+1) / 2 - 1LL * (n1-1) * n1 / 2;

        if (y2 + 1 <= C) {
            lint dd = 1LL * (C - (y2+1) + 1) * (D-C+1);
            printf("if %lld\n", dd);
            d += 1LL * (C - (y2+1) + 1) * (D-C+1);
        }
        printf("x %d - %lld\n", x, d);
        printf("y, n1, y2, n2 %d %d %d %d\n", y, n1, y2, n2);
        ans += d;
    }
    
    puts("");
    printf("%lld", ans);

}

#include <iostream>
using namespace std;
int main() {
    int N, M, pkg, one, min6 = 1000, min1 = 1000, ans = 0;
    scanf("%d%d", &N, &M);
    while (M--) {
        scanf("%d%d", &pkg, &one);
        min6 = min(pkg, min6);
        min1 = min(one, min1);
    }
    if (min6 < min1 * 6) {
        while (N > 6) {
            N -= 6;
            ans += min6;
        }
        if (min6 < min1 * N) ans += min6;
        else ans += min1 * N;
    }
    else ans = min1 * N;
    printf("%d", ans);
}
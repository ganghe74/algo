#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, X, Y, n, ans = 0;
    cin >> A >> B >> C >> X >> Y;
    if (2 * C < A + B) {
        n = min(X, Y) * 2;
        X -= n / 2;
        Y -= n / 2;
        ans += n * C;
    }
    if (X > 0 && 2 * C < A) {
        n = 2 * X;
        X -= n / 2;
        Y -= n / 2;
        ans += n * C;
    }
    if (Y > 0 && 2 * C < B) {
        n = 2 * Y;
        X -= n / 2;
        Y -= n / 2;
        ans += n * C;
    }
    if (X > 0) ans += A * X;
    if (Y > 0) ans += B * Y;
    printf("%d", ans);
}
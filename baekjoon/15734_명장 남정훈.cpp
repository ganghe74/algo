#include <bits/stdc++.h>
using namespace std;

int main() {
    int L, R, A;
    scanf("%d%d%d", &L, &R, &A);
    if (L > R) {
        if (L - R <= A) {
            A -= L - R;
            R = L;
        }
        else {
            R += A;
            A = 0;
        }
    }
    else if (L < R) {
        if (R - L <= A) {
            A -= R - L;
            L = R;
        }
        else {
            L += A;
            A = 0;
        }
    }
    if (L != R) {
        printf("%d", min(L, R) * 2);
    }
    else {
        printf("%d", (L + A / 2) * 2);
    }
}
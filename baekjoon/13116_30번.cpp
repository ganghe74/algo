#include <bits/stdc++.h>
using namespace std;
int main() {
    int T, A, B;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &A, &B);
        while (A != B) {
            if (A > B) A /= 2;
            else B /= 2;
        }
        printf("%d\n", 10*A);
    }
}
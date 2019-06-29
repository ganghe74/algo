#include <iostream>
using namespace std;
int main() {
    int L, R, i = 1, ans = 0;
    scanf("%d%d", &L, &R);
    L = L * R / 100;
    while (L > 5) {
        ans += L * (1 << i);
        L = L * R / 100;
        ++i;
    }
    printf("%d", ans);
}
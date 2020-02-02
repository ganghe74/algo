#include <bits/stdc++.h>
using namespace std;
int main() {
    int T, A, B;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &A, &B);
        printf("%lld\n", 1LL * (A/B) * (A/B));
    }
}

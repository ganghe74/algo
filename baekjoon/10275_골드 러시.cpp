#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        lint n, a, b, day = 0;
        scanf("%lld%lld%lld", &n, &a, &b);
        n = (1LL << n);
        while (a != 0 && b != 0) {
            n /= 2;
            day++;
            if (a >= n) a -= n;
            if (b >= n) b -= n;
        }
        printf("%lld\n", day);
    }
}
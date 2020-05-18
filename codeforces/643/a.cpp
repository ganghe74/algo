#include <bits/stdc++.h>
using namespace std;
using lint = long long;

lint t, n, k;

int main() {
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld%lld", &n, &k);
        while (--k) {
            int mindigit = 10;
            int maxdigit = -1;
            for (char c : to_string(n)) {
                int digit = c - '0';
                mindigit = min(mindigit, digit);
                maxdigit = max(maxdigit, digit);
            }
            if (mindigit == 0) break;
            n = n + mindigit * maxdigit;
        }
        printf("%lld\n", n);
    }
}

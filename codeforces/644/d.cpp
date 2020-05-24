#include <bits/stdc++.h>
using namespace std;

int t, n, k, p;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        for (int i=1;i*i<=n&&i<=k;++i) {
            if (n % i == 0) {
                p = i;
                int t = n/i;
                if (t <= k) {
                    p = t;
                    break;
                }
            }
        }
        printf("%d\n", n / p);
    }
}

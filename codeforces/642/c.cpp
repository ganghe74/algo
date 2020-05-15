#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        long long ans = 0;
        scanf("%d", &n);
        for (int i=3;i<=n;i+=2)
            ans += 1LL * (i/2) * (i * 4 - 4);
        printf("%lld\n", ans);
    }
}

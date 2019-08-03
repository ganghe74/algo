#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    while (scanf("%d%d", &n, &k) != EOF) {
        int ans = 0;
        while (n >= k) {
            ans += n / k * k;
            n = n % k + n / k;
        }
        printf("%d\n", ans+n);
    }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, ans = 0;
        scanf("%d", &n);
        while (n >= 2) {
            ans++;
            int i = 1;
            while (n >= i * 2 + i - 1) {
                n -= i * 2 + i - 1;
                i++;
            }
        }
        printf("%d\n", ans);
    }
}

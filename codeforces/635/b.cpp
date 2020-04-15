#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, x, n, m;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &x, &n, &m);
        while (n && x >= 20) {
            n--;
            x = x / 2 + 10;
        }
        while (m) {
            m--;
            x -= 10;
        }
        if (x <= 0) puts("YES");
        else puts("NO");
    }
}
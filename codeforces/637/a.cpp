#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, a, b, c, d;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
        if ((c-d <= n*(a-b) && n*(a-b) <= c+d) || (c-d <= n*(a+b) && n*(a+b) <= c+d) || (n*(a-b) <= c-d && n*(a+b) >= c+d)) puts("Yes");
        else puts("No");
    }
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m, ans = 0;
        scanf("%d%d", &n, &m);
        ans += n * (m/2);
        if (m%2 == 1)
            ans += (n+1)/2;
        printf("%d\n", ans);
    }
}

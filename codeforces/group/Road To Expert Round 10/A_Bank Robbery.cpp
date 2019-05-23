#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, n, x, ans = 0;
    scanf("%d %d %d", &a, &b, &c);
    scanf("%d", &n);
    for (int i=0;i<n;++i) {
        scanf("%d", &x);
        if (b < x && x < c) ans++;
    }
    printf("%d", ans);
}
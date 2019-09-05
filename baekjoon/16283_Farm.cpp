#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b, n, w, x, y, cnt = 0;
    cin >> a >> b >> n >> w;
    for (int i=1;i<n;++i) {
        if (a*i + b*(n-i) == w) {
            x = i;
            y = n - i;
            cnt++;
        }
    }
    if (cnt != 1) puts("-1");
    else printf("%d %d", x, y);
}
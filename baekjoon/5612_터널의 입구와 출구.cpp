#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, in, out;
    scanf("%d%d", &n, &m);
    int ans = m;
    while (n--) {
        scanf("%d%d", &in, &out);
        m += in - out;
        ans = max(ans, m);
        if (m < 0) {
            ans = 0;
            break;
        }
    }
    printf("%d", ans);
}
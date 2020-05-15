#include <bits/stdc++.h>
using namespace std;

int t, n, s[100001], d[100001];

int solve(int idx) {
    if (d[idx] != -1) return d[idx];
    d[idx] = 1;
    for (int i=2;idx*i<=n;++i)
        if (s[idx] < s[idx*i])
            d[idx] = max(d[idx], solve(idx*i)+1);
    return d[idx];
}

int main() {
    scanf("%d", &t);
    while (t--) {
        memset(d, -1, sizeof(d));
        scanf("%d", &n);
        for (int i=1;i<=n;++i)
            scanf("%d", &s[i]);
        int ans = 0;
        for (int i=1;i<=n;++i)
            ans = max(ans, solve(i));
        printf("%d\n", ans);
    }
}

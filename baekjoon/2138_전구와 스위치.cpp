#include <bits/stdc++.h>
using namespace std;

int n, x;
vector<int> a;

int solve(vector<int> a) {
    int cnt = 0;
    for (int i=2;i<=n;++i) {
        if (a[i-1]) {
            cnt++;
            a[i] = !a[i];
            a[i+1] = !a[i+1];
        }
    }
    if (a[n] == 1) return 1e9;
    return cnt;
}

int main() {
    scanf("%d", &n);
    a.resize(n+2);
    for (int i=1;i<=n;++i)
        scanf("%1d", &a[i]);
    for (int i=1;i<=n;++i) {
        scanf("%1d", &x);
        a[i] ^= x;
    }
    int ans = solve(a);
    a[1] = !a[1];
    a[2] = !a[2];
    ans = min(ans, solve(a)+1);
    if (ans == 1e9) ans = -1;
    printf("%d", ans);
}

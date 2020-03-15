#include <bits/stdc++.h>
using namespace std;
using lint = long long;

lint N, K, d[51][51];

lint solve(int n, int o) {
    if (n == 0) return (o != 0);
    if (o < 0) return (1LL << n);
    if (d[n][o]) return d[n][o];
    d[n][o] = solve(n-1, o-1) + solve(n-1, o+1);
    return d[n][o];
}

int main() {
    scanf("%lld%lld", &N, &K);
    if (++K > solve(N, 0)) puts("-1");
    else {
        int cnt = 0;
        while (N--) {
            if (K > solve(N, cnt+1)) {
                putchar(')');
                K -= solve(N, cnt+1);
                cnt--;
            }
            else {
                putchar('(');
                cnt++;
            }
            if (cnt < 0) cnt = -1e9;
        }
    }
}

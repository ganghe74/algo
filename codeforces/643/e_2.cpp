#include <bits/stdc++.h>
using namespace std;
using lint = long long;

lint n, a, r, m;
vector<lint> h, psum;

lint f(lint H) {
    lint x = lower_bound(h.begin(), h.end(), H) - h.begin() - 1;
    if (x < 0) x = 0;
    lint P = x * H - psum[x];
    lint Q = (psum[n] - psum[x]) - 1LL * (n-x) * H;
    if (P >= Q)
        return a * (P-Q) + m * Q;
    return r * (Q-P) + m * P;
}


int main() {
    scanf("%lld%lld%lld%lld", &n, &a, &r, &m);
    m = min(m, a+r);

    h.resize(n+1); psum.resize(n+1);
    for (int i=0;i<n;++i)
        scanf("%lld", &h[i]);
    sort(h.begin(), h.end());
    for (int i=1;i<=n;++i)
        psum[i] = psum[i-1] + h[i];

    lint ans = h[1];

    lint d = 1LL << 31;
    while (d) {
        if (ans+d <= h[n] && f(ans+d) < f(ans)) ans += d;
        else if (ans-d >= 0 && f(ans-d) < f(ans)) ans -= d;
        d /= 2;
    }
    printf("%lld", f(ans));
}

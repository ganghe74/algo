#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int N, K, a[15], l[15], ten[51];
lint d[1<<16][100];
string s[15];

lint solve(int status, int mod) {
    lint &ret = d[status][mod];
    if (ret != -1) return ret;
    if (__builtin_popcount(status) == N)
        return ret = (mod == 0);
    ret = 0;
    for (int i=0;i<N;++i)
        if (!(status & (1 << i)))
            ret += solve(status | (1 << i), (ten[l[i]] * mod + a[i]) % K);
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    memset(d, -1, sizeof(d));
    cin >> N;
    for (int i=0;i<N;++i) cin >> s[i];
    cin >> K;
    for (int i=0;i<N;++i) {
        l[i] = s[i].size();
        int n = 0;
        for (char c : s[i])
            n = (n * 10 + c - '0') % K;
        a[i] = n;
    }
    ten[0] = 1;
    for (int i=1;i<=50;++i) ten[i] = (ten[i-1] * 10) % K;
    lint p = solve(0, 0), q = 1;
    for (int i=1;i<=N;++i) q *= i;
    lint d = gcd(p, q);
    p /= d; q /= d;
    printf("%lld/%lld", p, q);
}

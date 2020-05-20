#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using matrix = vector<vector<lint>>;
const lint mod = 1e9+7;

matrix operator * (const matrix &a, const matrix &b) {
    matrix c(a.size(), vector<lint>(b[0].size()));
    for (int i=0;i<a.size();++i) {
        for (int j=0;j<b[0].size();++j) {
            for (int k=0;k<b.size();++k) {
                c[i][j] += a[i][k] * b[k][j];
                c[i][j] %= mod;
            }
        }
    }
    return c;
}

matrix fastpow(const matrix &a, lint n) {
    if (n == 0) {
        matrix b(a.size(), vector<lint>(a.size()));
        for (int i=0;i<a.size();++i)
            b[i][i] = 1;
        return b;
    }
    if (n == 1) return a;
    if (n % 2 == 1) return a * fastpow(a, n-1);
    auto t = fastpow(a, n/2);
    return t * t;
}

lint n, m;

int main() {
    cin >> n >> m;
    matrix c(1<<m, vector<lint>(1<<m));
    for (int pstate=0; pstate<(1<<m); ++pstate) {
        for (int state=0; state<(1<<m); ++state) {
            bool has22 = false;
            for (int i=1;i<m;++i) {
                int x = !(pstate & (1 << i));
                if (x == !(pstate & (1 << (i-1))) && x == !(state & (1 << i)) && x == !(state & (1 << (i-1))))
                    has22 = true;
            }
            if (!has22) {
                c[state][pstate] = 1;
            }
        }
    }

    matrix d1(1<<m, vector<lint>(1,1));
    matrix dn = fastpow(c, n-1) * d1;
    lint ans = 0;
    for (int i=0;i<(1<<m);++i)
        ans = (ans + dn[i][0]) % mod;
    cout << ans;
}

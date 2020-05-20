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

    if (n == 1) {
        printf("%lld", m);
        return 0;
    }

    matrix eo(m, vector<lint>(m));
    matrix oe = eo;
    for (int i=0;i<m;++i) {
        if (i-1 >= 0) oe[i][i-1] = eo[i][i-1] = 1;
        eo[i][i] = 1;
        if (i+1 < m) oe[i][i+1] = eo[i][i+1] = 1;
    }
    matrix oo = eo * oe;
    matrix d1(m, vector<lint>(1, 1));

    matrix dn = fastpow(oo, (n-1)/2);
    if (n % 2 == 0)
        dn = oe * dn;
    dn = dn * d1;

    lint ans = 0;
    for (auto &row : dn)
        ans = (ans + row[0]) % mod;
    cout << ans;
}

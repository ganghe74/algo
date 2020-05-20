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

lint n, k;

int getidx(int a, bool b, bool c) {
    return k*(b+2*c) + a;
}

int main() {
    cin >> n >> k;
    if (n == 1) {
        puts("1");
        return 0;
    }
    matrix m(4*k, vector<lint>(4*k));
    for (int a=0;a<k;++a) {
        for (int b=0;b<2;++b) {
            for (int c=0;c<2;++c) {
                int r = getidx(a, b, c);
                if (b) {
                    m[r][getidx(a, 0, c)]++;
                }
                else {
                    m[r][getidx((a+k-1)%k, 0, c)]++;
                    m[r][getidx((a+k-1)%k, 1, c)]++;
                    if (c) {
                        m[r][getidx(a, 0, 0)]++;
                        m[r][getidx(a, 0, 1)]++;
                        m[r][getidx(a, 1, 0)]++;
                        m[r][getidx(a, 1, 1)]++;
                    }
                }
            }
        }
    }
    matrix d1(4*k, vector<lint>(1));
    if (k) {
        d1[getidx(1%k, 0, 0)][0] = 1;
        d1[getidx(0, 1, 0)][0] = 1;
        d1[getidx(0, 0, 1)][0] = 1;
    }
    else {
        m = {
            {1, 1},
            {1, 0}
        };
        d1 = {
            {1},
            {1}
        };
    }
    
    matrix dn = fastpow(m, n-1) * d1;
    if (k) cout << (dn[getidx(0, 0, 1)][0] + dn[getidx(0, 1, 1)][0]) % mod;
    else cout << (dn[0][0] + dn[1][0]) % mod;
}

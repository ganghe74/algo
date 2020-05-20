#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using matrix = vector<vector<lint>>;
const lint mod = 1234567891;

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
    if (n == 1) return a;
    if (n % 2 == 1) return a * fastpow(a, n-1);
    auto t = fastpow(a, n/2);
    return t * t;
}

lint n, l, x;
lint a44, a47, a74, a77;
set<lint> nums;

int main() {
    cin >> n >> l;
    for (int i=0;i<n;++i) {
        cin >> x;
        nums.insert(x);
    }
    for (auto x : nums) {
        string s = to_string(x);
        bool ok = true;
        for (char c : s)
            if (c != '4' && c != '7')
                ok = false;
        if (ok) {
            if (s.front() == '4') {
                if (s.back() == '4') a44++;
                else a47++;
            }
            else {
                if (s.back() == '4') a74++;
                else a77++;
            }
        }
    }
    matrix a = {
        {a44, a74, 0, 0},
        {a47, a77, 0, 0},
        {0, 0, a44, a74},
        {0, 0, a47, a77}
    };
    matrix d0 = {
        {1},
        {0},
        {0},
        {1}
    };
    matrix dn = fastpow(a, l) * d0;
    cout << (dn[0][0] + dn[1][0] + dn[2][0] + dn[3][0]) % mod;
}

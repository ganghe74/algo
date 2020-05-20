#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using matrix = vector<vector<lint>>;
const lint mod = 1e9+7;
matrix operator * (const matrix &a, const matrix &b) {
    matrix c(a.size(), vector<lint>(b[0].size()));
    for (int i=0; i<a.size(); ++i) {
        for (int j=0; j<b[0].size(); ++j) {
            for (int k=0; k<b.size(); ++k)
                c[i][j] += a[i][k] * b[k][j];
            c[i][j] %= mod;
        }
    }
    return c;
}

matrix powm(const matrix &a, lint n) {
    if (n == 1) return a;
    if (n % 2 == 1) return powm(a, n-1) * a;
    auto t = powm(a, n/2);
    return t * t;
}

int main() {
    lint n;
    cin >> n;
    matrix a = {
        {0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 1},
        {0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 1, 0, 0, 1, 0}
    };
    matrix d1 = {
        {1},
        {0},
        {0},
        {1},
        {0},
        {0},
        {1},
        {0},
    };

    auto dn = powm(a, n-1) * d1;
    printf("%lld", dn[7][0]);
}

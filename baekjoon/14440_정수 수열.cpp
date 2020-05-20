#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using matrix = vector<vector<lint>>;

matrix operator * (const matrix &a, const matrix &b) {
    matrix c(a.size(), vector<lint>(b[0].size()));
    for (int i=0;i<a.size();++i) {
        for (int j=0;j<b[0].size();++j) {
            for (int k=0;k<b.size();++k)
                c[i][j] += a[i][k] * b[k][j];
            c[i][j] %= 100000000;
        }
    }
    return c;
}

matrix fastpow(const matrix &a, int n) {
    if (n == 1) return a;
    if (n % 2 == 1) return a * fastpow(a, n-1);
    auto t = fastpow(a, n/2);
    return t * t;
}

int main() {
    int x, y, a0, a1, n;
    scanf("%d%d%d%d%d", &x, &y, &a0, &a1, &n);
    matrix d = {
        {x, y},
        {1, 0}
    };
    matrix a = {
        {a1},
        {a0}
    };
    if (n <= 1) {
        if (n == 0) printf("%02d", a0);
        else printf("%02d", a1);
        return 0;
    }
    matrix an = fastpow(d, n-1) * a;
    printf("%02lld", an[0][0] % 100);
}

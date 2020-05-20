#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using matrix = vector<vector<lint>>;
const lint mod = 1e9+9;

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

int t, n, m;

int getbit(int r, int c) {
    return (1 << (r*m)) << c;
}

const int dr[] = {-2, -1, 1, 2};
const int dc[] = {1, 2, 2, 1};

bool check(int state) {
    for (int i=0; i<3; ++i) {
        for (int j=0; j<m; ++j) {
            if (state & getbit(i, j)) {
                for (int k=0;k<4;++k) {
                    int nr = i + dr[k];
                    int nc = j + dc[k];
                    if (0 <= nr && nr < 3 && 0 <= nc && nc < m)
                        if (state & getbit(nr, nc))
                            return false;
                }
            }
        }
    }
    return true;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &m, &n);
        matrix c(1<<(m*2), vector<lint>(1<<(m*2)));
        for (int pstate=0; pstate<(1<<(m*2)); ++pstate) {
            for (int d=0; d<(1<<m); ++d) {
                if (check(pstate | (d << (m*2)))) {
                    int state = (pstate >> m) | (d << m);
                    c[state][pstate]++;
                }
            }
        }

        matrix d1(1<<(m*2), vector<lint>(1));
        
        for (int state=0; state<(1<<m); ++state)
            d1[state<<m][0] = 1;

        matrix dn = fastpow(c, n-1) * d1;

        lint ans = 0;
        for (auto &row : dn)
            ans = (ans + row[0]) % mod;
        printf("%lld\n", ans);
    }
}

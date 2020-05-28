#include <bits/stdc++.h>
using namespace std;
using matrix = vector<vector<double>>;

int tc, n, k, m, length[50];
double T[50][50];

matrix operator * (const matrix &a, const matrix &b) {
    matrix c(a.size(), vector<double>(b[0].size()));
    for (int i=0;i<a.size();++i)
        for (int j=0;j<b[0].size();++j)
            for (int k=0;k<b.size();++k)
                c[i][j] += a[i][k] * b[k][j];
    return c;
}

matrix fastpow(matrix &a, int k) {
    if (k == 1) return a;
    if (k % 2 == 1) return a * fastpow(a, k-1);
    matrix t = fastpow(a, k/2);
    return t * t;
}

vector<double> getProb1() {
    double c[5][50];
    memset(c, 0, sizeof(c));
    c[0][0] = 1.0;
    for (int time=1; time<=k; ++time)
        for (int song=0; song<n; ++song) {
            double &prob = c[time % 5][song];
            prob = 0;
            for (int last=0; last<n; ++last)
                prob += c[(time-length[last] + 5) % 5][last] * T[last][song];
        }
    vector<double> ret(n);
    for (int song=0; song<n; ++song)
        for (int start=k-length[song]+1; start<=k;++start)
            ret[song] += c[start % 5][song];
    return ret;
}

vector<double> getProb2() {
    matrix W(4*n, vector<double>(4*n));
    for (int i=0; i<3*n; ++i)
        W[i][i+n] = 1.0;
    for (int i=0;i<n;++i)
        for (int j=0;j<n;++j)
            W[3*n+i][(4-length[j])*n+j] = T[j][i];
    matrix Wk = fastpow(W, k);
    vector<double> ret(n);
    for (int song=0; song<n; ++song)
        for (int start=0; start<length[song]; ++start)
            ret[song] += Wk[(3-start)*n+song][3*n];
    return ret;
}

int main() {
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d%d%d", &n, &k, &m);
        for (int i=0;i<n;++i)
            scanf("%d", &length[i]);
        for (int i=0;i<n;++i)
            for (int j=0;j<n;++j)
                scanf("%lf", &T[i][j]);
        auto prob = getProb2();
        while (m--) {
            int love;
            scanf("%d", &love);
            printf("%.9lf ", prob[love]);
        }
        puts("");
    }
}

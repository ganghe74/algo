#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int MOD = 1e6+3;
int N, S, E, T, d;
vector<vector<lint>> a;

vector<vector<lint>> gob(vector<vector<lint>> a, vector<vector<lint>> b) {
    vector<vector<lint>> ret(N*5, vector<lint>(N*5));
    for (int i=0;i<N*5;++i) {
        for (int j=0;j<N*5;++j) {
            int x = 0;
            for (int k=0;k<N*5;++k)
                x = (x + a[i][k] * b[k][j]) % MOD;
            ret[i][j] = x;
        }
    }
    return ret;
}

vector<vector<lint>> jegob(vector<vector<lint>> a, int b) {
    if (b == 1) return a;
    if (b % 2 == 1) return gob(a, jegob(a, b-1));
    vector<vector<lint>> temp(N*5, vector<lint>(N*5));
    temp = jegob(a, b/2);
    return gob(temp, temp);
}

int main() {
    scanf("%d%d%d%d", &N, &S, &E, &T);
    a.assign(N*5, vector<lint>(N*5));

    for (int i=0;i<N;++i)
        for (int j=0;j<4;++j) a[i*5+j+1][i*5+j] = 1;

    for (int i=0;i<N;++i) {
        for (int j=0;j<N;++j) {
            scanf("%1d", &d);
            if (d) a[i*5][j*5+d-1] = 1;
        }
    }
    a = jegob(a, T);
    
    printf("%lld", a[5*(S-1)][5*(E-1)]);
}

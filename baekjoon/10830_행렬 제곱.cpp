#include <bits/stdc++.h>
using namespace std;
long long N, B;
vector<vector<int>> gob(vector<vector<int>> a, vector<vector<int>> b) {
    vector<vector<int>> ret(N, vector<int>(N));
    for (int i=0;i<N;++i) {
        for (int j=0;j<N;++j) {
            int x = 0;
            for (int k=0;k<N;++k) {
                x += a[i][k] * b[k][j];
                x %= 1000;
            }
            ret[i][j] = x;
        }
    }
    return ret;
}
vector<vector<int>> jegob(vector<vector<int>> a, long long b) {
    if (b == 1) return a;
    if (b % 2 == 1) return gob(a, jegob(a, b-1));
    vector<vector<int>> temp(N, vector<int>(N));
    temp = jegob(a, b/2);
    return gob(temp, temp);
}
int main() {
    scanf("%lld%lld", &N, &B);
    vector<vector<int>> a(N, vector<int>(N));
    for (int i=0;i<N;++i) {
        for (int j=0;j<N;++j) scanf("%d", &a[i][j]);
    }
    a = jegob(a, B);
    for (int i=0;i<N;++i) {
        for (int j=0;j<N;++j) printf("%d ", a[i][j] % 1000);
        puts("");
    }
}
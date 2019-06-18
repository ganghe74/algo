#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
const int MOD= 1e9+7;
vector<vector<lint>> gob(vector<vector<lint>> a, vector<vector<lint>> b) {
    vector<vector<lint>> ret(a.size(), vector<lint>(b[0].size()));
    for (lint i=0;i<a.size();++i) {
        for (lint j=0;j<b[0].size();++j) {
            lint x = 0;
            for (lint k=0;k<b.size();++k) {
                x += a[i][k] * b[k][j];
                x %= MOD;
            }
            ret[i][j] = x;
        }
    }
    return ret;
}
vector<vector<lint>> jegob(vector<vector<lint>> a, lint b) {
    if (b == 1) return a;
    if (b % 2 == 1) return gob(a, jegob(a, b-1));
    vector<vector<lint>> temp(a.size(), vector<lint>(a.size()));
    temp = jegob(a, b/2);
    return gob(temp, temp);
}
lint fibo(lint n) {
    vector<vector<lint>> a = {{1,1},{1,0}};
    a = gob(jegob(a,n), {{1},{0}});
    return a[1][0];
}
int main() {
    lint n;
    cin >> n;
    n = (n+1) / 2;
    cout << fibo(2*n);
}
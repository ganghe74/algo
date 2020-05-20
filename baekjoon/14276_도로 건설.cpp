#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
int n, m, k, d[31][31][31][1<<9];

int solve(int num, int rem, int lodist, int state) {
    if (num == n)
        return (!rem && !state);
    int &ret = d[num][rem][lodist][state];
    if (ret != -1)
        return ret;
    ret = 0;
    if (!(state & 1))
        ret = solve(num+1, rem, 1, state >> 1);
    for (int i=lodist;i<=k;++i) {
        if (rem && num+i < n) {
            ret = (ret + solve(num, rem-1, i, state ^ 1 ^ (1<<i))) % mod;
        }
    }
    return ret;
}

int main() {
    memset(d, -1, sizeof(d));
    scanf("%d%d%d", &n, &m, &k);
    printf("%d", solve(0, m, 1, 0));
}

#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int n, m, pow3[10], d[800][6561];

int solve(int num, int state) {
    if (num == n*m) {
        while (state) {
            if (state % 3 == 1)
                return 0;
            state /= 3;
        }
        return 1;
    }
    int &ret = d[num][state];
    if (ret != -1)
        return ret;
    ret = 0;
    int up = state / pow3[m-1];
    int left = state % 3;
    int cleft = 2;
    if (left <= 1) cleft = 1 - left;
    int nstate = (state - up*pow3[m-1] - left) * 3;
    int cur = ((left <= 1) != (up <= 1));
    if (num % m == 0) {
        cleft = left;
        cur = (up == 1) ? 1 : 0;
    }
    if (up == 0)
        ret = (ret + solve(num+1, nstate + left*3 + 2)) % mod;
    else if (up == 1)
        ret = (ret + solve(num+1, nstate + cleft*3 + cur)) % mod;
    else if (up == 2) {
        ret = (ret + solve(num+1, nstate + left*3 + 2)) % mod;
        ret = (ret + solve(num+1, nstate + cleft*3 + cur)) % mod;
    }
    return ret;
}

int main() {
    memset(d, -1, sizeof(d));
    pow3[0] = 1;
    for (int i=1;i<10;++i)
        pow3[i] = pow3[i-1] * 3;
    scanf("%d%d", &n, &m);
    int state = 0;
    for (int i=0;i<m;++i)
        state += 2 * pow3[i];
    printf("%d", solve(0, state));
}

#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;

int n, k, d[100000][10][2][2];

int solve(int num, int a, bool b, bool c) {
    if (num == n && !a && c)
        return 1;
    if (num >= n)
        return 0;
    int &ret = d[num][a][b][c];
    if (ret != -1)
        return ret;
    ret = 0;
    if (k)
        ret = solve(num+1, (a+1)%k, false, c);
    if (!b)
        ret = (ret + solve(num+1, a, true, c)) % mod;
    ret = (ret + solve(num+1, a, false, true)) % mod;
    return ret;
}

int main() {
    memset(d, -1, sizeof(d));
    scanf("%d%d", &n, &k);
    printf("%d", solve(0, 0, 0, 0));
}

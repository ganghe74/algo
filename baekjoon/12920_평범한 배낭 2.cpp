#include <bits/stdc++.h>
using namespace std;

int n, m, dn, x, y, z, w[2000], v[2000], d[2000][10001];

int solve(int num, int wei) {
    if (wei < 0) return -1e9;
    if (num == dn) return 0;
    int &ret = d[num][wei];
    if (ret != -1) return ret;
    return ret = max(solve(num+1, wei), solve(num+1, wei-w[num]) + v[num]);
}

int main() {
    memset(d, -1, sizeof(d));
    scanf("%d%d", &n, &m);
    while (n--) {
        scanf("%d%d%d", &x, &y, &z);
        for (int i=1;z>0;i*=2) {
            i = min(i, z);
            w[dn] = x * i;
            v[dn] = y * i;
            dn++;
            z -= i;
        }
    }
    printf("%d", solve(0, m));
}

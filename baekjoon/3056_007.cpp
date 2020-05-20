#include <bits/stdc++.h>
using namespace std;

int n;
double a[20][20], d[1<<20];

double solve(int state) {
    int num = __builtin_popcount(state);
    if (num == n) return 1.0;
    double &ret = d[state];
    if (ret != -1) return ret;
    for (int i=0;i<n;++i)
        if (!(state & (1 << i)))
            ret = max(ret, a[num][i] * solve(state | (1 << i)));
    return ret;
}

int main() {
    fill(d, d + (1<<20), -1);
    scanf("%d", &n);
    for (int i=0;i<n;++i) {
        for (int j=0;j<n;++j) {
            scanf("%lf", &a[i][j]);
            a[i][j] /= 100;
        }
    }
    printf("%lf", solve(0) * 100);
}

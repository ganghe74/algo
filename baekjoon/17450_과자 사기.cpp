#include <bits/stdc++.h>
using namespace std;
using lint = long long;
int main() {
    lint p[3], w[3];
    for (int i=0;i<3;++i) {
        scanf("%lld%lld", &p[i], &w[i]);
        p[i] *= 10;
        w[i] *= 10;
        if (p[i] >= 5000) p[i] -= 500;
    }
    w[0] *= p[1] * p[2];
    w[1] *= p[0] * p[2];
    w[2] *= p[0] * p[1];
    if (w[0] > w[1] && w[0] > w[2]) puts("S");
    else if (w[1] > w[0] && w[1] > w[2]) puts("N");
    else puts("U");
}

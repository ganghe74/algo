#include <bits/stdc++.h>
using namespace std;
using lint = long long;

lint K, d[91][2];

lint solve(int n, bool bit) {
    if (n == 0) return bit;
    if (n == 1) return n;
    lint &ret = d[n][bit];
    if (ret) return ret;
    ret = solve(n-1, 0);
    if (!bit) ret += solve(n-1, 1);
    return ret;
}

int main() {
    scanf("%lld", &K);
    int l;
    for (l=1;K>solve(l,1);++l) K -= solve(l,1);
    bool p = 1;
    printf("1");
    l--;
    while (l--) {
        if (p) p = 0;
        else {
            if (K > solve(l, 0) + solve(l, 1)) {
                p = 1;
                K -= solve(l, 0) + solve(l, 1);
            }
            else p = 0;
        }
        printf("%d", p);
    }
}

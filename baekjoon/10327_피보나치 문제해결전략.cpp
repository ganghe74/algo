#include <bits/stdc++.h>

using namespace std;
using lint = long long;
lint fibo[50];

int main() {
    fibo[0] = 1;
    fibo[1] = 1;
    for (int i=2;i<45;++i)
        fibo[i] = fibo[i-1] + fibo[i-2];

    lint t, n;
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld", &n);
        lint a = 1, b = n-1;
        for (lint y=1;y<2*sqrt(n)+1;++y) {
            for (int i=1;i<45;++i) {
                if (fibo[i-1] + fibo[i] * y > n) break;
                lint tmp = n - fibo[i] * y;
                if (tmp % fibo[i-1] != 0) continue;
                lint x = tmp / fibo[i-1];
                if (x <= y && x > 0 && (y < b || (y == b && x < a))) {
                    a = x;
                    b = y;
                }
            }
        }

        printf("%lld %lld\n", a, b);
    }
}

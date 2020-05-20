#include <bits/stdc++.h>
using namespace std;
using lint = __int128;

tuple<lint,lint,lint> exgcd(lint a, lint b) {
    if (!b) return {a, 1, 0};
    auto [d, x, y] = exgcd(b, a%b);
    return {d, y, x-y*(a/b)};
}

int main() {
    long long tmp1, tmp2, tmp3;
    cin >> tmp1 >> tmp2 >> tmp3;
    lint a = tmp1, b = tmp2, s = tmp3;
    auto [d, x, y] = exgcd(a, b);
    if (a == 0 || b == 0) {
        if (!a && !b) puts(!s ? "YES" : "NO");
        else if (!a) puts((s%b==0) ? "YES" : "NO");
        else if (!b) puts((s%a==0) ? "YES" : "NO");
        return 0;
    }
    if (s % d == 0) {
        x *= s / d;
        y *= s / d;
        for (lint k=-d*x/b-5;k<d*y/a+5;++k) {
            lint xx = x+b/d*k;
            lint yy = y-a/d*k;
            if (xx >= 0 && yy >= 0) {
                if (get<0>(exgcd(xx, yy)) == 1) {
                    puts("YES");
                    return 0;
                }
            }
        }
    }
    puts("NO");
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long b, d, s;
    scanf("%lld %lld %lld", &b, &d, &s);

    long long m, ans = 3e+18;
    for (int start=0;start<3;++start) {
        for (int end=0;end<3;++end) {
            long long a[3] = {b, d, s};
            int i = start;
            while (i != end) {
                a[i]--;
                i = (i + 1) % 3;
            }
            m = max(max(a[0], a[1]), a[2]);
            ans = min(ans, -(a[0]+a[1]+a[2] - 3*m));
        }
    }

    printf("%lld", ans);
}
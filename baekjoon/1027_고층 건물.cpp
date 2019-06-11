#include <bits/stdc++.h>
using namespace std;
long long a[50], cnt[50];
long long ccw(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
    long long temp = x1*y2+x2*y3+x3*y1;
    temp = temp - y1*x2-y2*x3-y3*x1;
    if (temp > 0) {
        return 1;
    } else if (temp < 0) {
        return -1;
    } else {
        return 0;
    }
}
int main() {
    long long N;
    scanf("%d", &N);
    for (long long i=0;i<N;++i) scanf("%d", &a[i]);
    for (long long i=0;i<N;++i) {
        for (long long j=i+1;j<N;++j) {
            bool ok = true;
            for (long long k=i+1;k<j;++k) {
                if (ccw(i, a[i], k, a[k], j, a[j]) != 1) ok = false;
            }
            if (ok) {
                cnt[i]++;
                cnt[j]++;
            }
        }
    }
    long long ans = 0;
    for (long long i=0;i<N;++i) ans = max(ans, cnt[i]);
    printf("%d", ans);
}
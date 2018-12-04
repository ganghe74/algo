#include <iostream>
using namespace std;
int K, N;
int a[10000];
bool check(long long x) {
    long long cnt = 0;
    for (int i=0;i<K;++i) {
        cnt += a[i]/x;
    }
    return cnt >= N;
}
int main() {
    scanf("%d%d", &K, &N);
    int max = 0;
    for (int i=0;i<K;++i) {
        scanf("%d", &a[i]);
        if (max < a[i]) max = a[i];
    }
    long long l = 1, r = max;
    long long ans = 0;
    while (l<=r) {
        long long mid = (l+r)/2;
        if (check(mid)) {
            if (ans < mid) ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    printf("%lld", ans);
}
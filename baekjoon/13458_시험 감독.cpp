#include <iostream>
using namespace std;
int a[1000000];
int main() {
    int N, B, C;
    long long ans = 0;
    scanf("%d", &N);
    for (int i=0;i<N;++i) scanf("%d", &a[i]);
    scanf("%d%d", &B, &C);
    for (int i=0;i<N;++i) {
        a[i] -= B;
        if (a[i] > 0) ans += (a[i] + C-1)/C;
        ans++;
    }
    printf("%lld", ans);
}
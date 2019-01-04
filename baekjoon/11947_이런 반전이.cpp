#include <iostream>
using namespace std;
long long reverse(int a) {
    long long ret = 0, p = 1;
    while (a > 0) {
        ret += (9 - a%10) * p;
        a /= 10;
        p *= 10;
    }
    return ret;
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, p = 1;
        scanf("%d", &N);
        while (p*10 <= N) p*=10;
        if (N/p >= 5) printf("%lld\n", p*5 * reverse(p*5));
        else printf("%lld\n", N * reverse(N));
    }
}
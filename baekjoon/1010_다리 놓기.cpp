#include <iostream>
using namespace std;
int combination(int n, int r) {
    if (n/2 < r) return combination(n, n-r);
    long long ret = 1;
    for (int i=n;i>n-r;--i) ret *= i;
    for (int i=1;i<=r;++i) ret /= i;
    return ret;
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, M;
        scanf("%d%d", &N, &M);
        printf("%d\n", combination(M, N));
    }
}
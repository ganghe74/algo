#include <iostream>
using namespace std;
int f(int n) {
    int ret = 0;
    while (n > 0) {
        ret = ret * 10 + n % 10;
        n /= 10;
    }
    return ret;
}
int main() {
    int N, K, ans = 0;
    scanf("%d%d", &N, &K);
    for (int i=1;i<=K;++i) {
        ans = max(ans , f(N*i));
    }
    printf("%d", ans);
}
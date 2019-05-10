#include <iostream>
using namespace std;
int main() {
    int N, ans = 1;
    scanf("%d", &N);
    for (int i=1;i<=N;++i) {
        ans *= i;
        while (ans % 10 == 0) ans /= 10;
        if (ans > 100000) ans %= 100000;
    }
    printf("%d", ans % 10);
}
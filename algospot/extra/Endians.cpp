#include <iostream>
using namespace std;
int main() {
    int C;
    scanf("%d", &C);
    while (C--) {
        unsigned n, ans = 0;
        scanf("%u", &n);
        for (int i=0;i<4;++i) {
            ans = ans << 8;
            ans += n & 255;
            n = n >> 8;
        }
        printf("%u\n", ans);
    }
}
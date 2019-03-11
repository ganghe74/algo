#include <iostream>
using namespace std;
int main() {
    int N, ans = 0;
    scanf("%d", &N);
    while (N--) {
        int a, b, c, prize = 0;
        scanf("%d%d%d", &a, &b, &c);
        if (a == b && b == c) prize = 10000 + a * 1000;
        else if (a == b || a == c) prize = 1000 + a * 100;
        else if (b == c) prize = 1000 + b * 100;
        else prize = max(max(a, b), c) * 100;
        ans = max(ans , prize);
    }
    printf("%d", ans);
}
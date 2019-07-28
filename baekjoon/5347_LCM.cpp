#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
lint gcd(lint a, lint b) {
    if (b == 0) return a;
    return gcd(b , a % b);
}
lint lcm(lint a, lint b) {
    return a * b / gcd(a, b);
}
int main() {
    int n, a, b;
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d", &a, &b);
        printf("%lld\n", lcm(a, b));
    }
}
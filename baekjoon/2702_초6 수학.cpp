#include <iostream>
using namespace std;
int gcd(int a, int b) {
    return b == 0?a:gcd(b, a%b);
}
int lcm(int a, int b) {
    return a * b / gcd(a,b);
}
int main() {
    int T, a, b;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &a, &b);
        printf("%d %d\n", lcm(a, b), gcd(a,b));
    }
}
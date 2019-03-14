#include <iostream>
#define lint long long
using namespace std;
lint gcd(lint a, lint b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}
int main() {
    lint A, B, len;
    scanf("%lld%lld", &A, &B);
    len = gcd(A, B);
    while(len--) putchar('1');
}
#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}
int main() {
    int a, b, n, x;
    scanf("%d", &n);
    scanf("%d%d", &a, &b);
    x = gcd(a, b);
    if (n == 3) {
        scanf("%d", &a);
        x = gcd(a, x);
    }
    for (int i=1;i<=x;++i) {
        if (x % i == 0) printf("%d\n", i);
    }
}
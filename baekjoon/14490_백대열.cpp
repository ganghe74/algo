#include <iostream>
using namespace std;
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}
int main() {
    int A, B, g;
    scanf("%d:%d", &A, &B);
    g = gcd(A,B);
    printf("%d:%d", A/g, B/g);
}
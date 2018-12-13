#include <iostream>
using namespace std;
long long gcd(long long a, long long b) {
    return b==0?a:gcd(b,a%b);
}
long long lcm(long long a, long long b) {
    return a * b / gcd(a,b);
}
int main() {
    long long A, B;
    scanf("%lld %lld", &A, &B);
    printf("%lld", lcm(A,B));
}
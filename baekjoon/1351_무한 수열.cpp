#include <iostream>
#include <map>
using namespace std;
long long N, P, Q;
map<long long, long long> d;
long long sequence(long long n) {
    if (n == 0) return 1;
    if (d[n] > 0) return d[n];
    d[n] = sequence(n/P) + sequence(n/Q);
    return d[n];
}
int main() {
    scanf("%lld%lld%lld", &N, &P, &Q);
    printf("%lld", sequence(N));
}
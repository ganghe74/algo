#include <iostream>
using namespace std;
int main() {
    long long A, B;
    scanf("%lld%lld", &A, &B);
    if (A > B) swap(A,B);
    printf("%lld\n", max(0LL,B-A-1));
    for (long long i=A+1;i<B;++i) {
        printf("%lld ", i);
    }
}
#include <iostream>
using namespace std;
int main() {
    int t;
    long long a, b, k;
    scanf("%d", &t);
    while (t--) {
        scanf("%lld %lld %lld", &a, &b, &k);
        if (k%2 == 1) printf("%lld\n", a*(k/2+1) - b*(k/2));
        else printf("%lld\n", a*(k/2) - b*(k/2));
    }
}
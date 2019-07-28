#include <iostream>
using namespace std;
int main() {
    unsigned long long ans = 1, n, m, a;
    scanf("%llu %llu", &n, &m);
    while (n--) {
        scanf("%llu", &a);
        ans = ans * (a % m) % m;
    }
    printf("%llu", ans);
}
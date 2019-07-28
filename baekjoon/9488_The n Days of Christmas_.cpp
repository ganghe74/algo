#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    while (true) {
        scanf("%lld", &n);
        if (n == 0) break;
        printf("%lld\n", n * (n+1) * (n+2) / 6);
    }
}
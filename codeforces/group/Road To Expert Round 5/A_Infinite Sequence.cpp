#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m = 1;
    scanf("%lld", &n);
    while (n > m) {
        n -= m;
        m++;
    }
    printf("%lld", n);
}
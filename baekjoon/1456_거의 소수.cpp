#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
bool c[10000001];
int main() {
    vector<int> primes;
    for (int i=2;i<=10000000;++i) {
        if (!c[i]) {
            primes.push_back(i);
            for (int j=2;i*j<=10000000;++j) c[i*j] = 1;
        }
    }
    lint a, b, cnt = 0;
    scanf("%lld%lld", &a, &b);
    for (int x : primes) {
        lint n = 1LL * x * x;
        while (true) {
            if (a <= n && n <= b) cnt++;
            if (n <= b / x) n *= x;
            else break;
        }
    }
    printf("%lld", cnt);
}
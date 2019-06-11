#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
lint a, b, MOD;
lint f(lint a, lint b) {
    if (b == 0) return 1;
    else if (b == 1) return a % MOD;
    else if (b % 2 == 0) {
        lint temp = f(a, b/2) % MOD;
        return temp * temp % MOD;
    }
    else {
        return a * f(a, b-1) % MOD;
    }
}
int main() {
    cin >> a >> b >> MOD;
    cout << f(a, b) % MOD;
}
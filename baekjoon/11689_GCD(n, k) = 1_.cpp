#include <bits/stdc++.h>
using namespace std;
using lint = long long;

lint f(lint n) {
    lint ret = n;
    for (lint i=2;i*i<=n;++i) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            ret -= ret / i;
        }
    }
    if (n > 1) ret -= ret / n;
    return ret;

}

int main() {
    lint n;
    cin >> n;
    cout << f(n);
}